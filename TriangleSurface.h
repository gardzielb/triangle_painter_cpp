//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_TRIANGLESURFACE_H
#define TRIANGLE_PAINTER_TRIANGLESURFACE_H


#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <utility>
#include "PolygonPainter.h"
#include "QtPolygonPainter.h"
#include "AdvancedPixelPainter.h"
#include "Polygon.h"

class TriangleSurface : public QWidget
{
private:
	QPainter * painter = nullptr;
	PixelPainter * pixel_painter = nullptr;
	PolygonPainter * polygon_painter = nullptr;
	QPixmap * pixmap = nullptr;

	int row_count;
	int col_count;
	TriangleGrid * grid = nullptr;

	QPoint * active_point = nullptr;
	int active_row = -1;
	int active_col = -1;
	std::list<Polygon *> active_triangles;
	std::list<Polygon *> triangle_paint_list;

	bool draw_borders = true;
	bool is_mouse_pressed = false;

	const int POINT_HIT_RADIUS = 5;

public:
	TriangleSurface( int row_count, int col_count )
			: row_count( row_count ), col_count( col_count )
	{
		setFixedSize( 800, 800 );
		pixmap = new QPixmap( width(), height() );

		painter = new QPainter();
		pixel_painter = new AdvancedPixelPainter( painter, PainterSettings() );
		polygon_painter = new QtPolygonPainter( painter, pixel_painter );

		create_triangle_grid();
		setMouseTracking( true );
	}

	void paintEvent( QPaintEvent * event ) override
	{
		painter->begin( this );
		painter->drawPixmap( rect(), *pixmap );
		paint_triangles( &active_triangles );

		if ( active_point )
		{
			polygon_painter->draw_active_point( active_point->x(), active_point->y(), POINT_HIT_RADIUS );
		}

		painter->end();
	}

	void mousePressEvent( QMouseEvent * event ) override
	{
		is_mouse_pressed = true;
		if ( !active_point ) return;

		find_active_triangles( active_row, active_col );
		for ( auto triangle : active_triangles )
		{
			triangle_paint_list.remove( triangle );
		}

		full_repaint();
	}

	void mouseReleaseEvent( QMouseEvent * event ) override
	{
		is_mouse_pressed = false;
		for ( auto triangle : active_triangles )
		{
			triangle_paint_list.push_back( triangle );
		}
		active_triangles.clear();
		active_point = nullptr;
		active_row = -1;
		active_col = -1;
		full_repaint();
	}

	void mouseMoveEvent( QMouseEvent * event ) override
	{
		if ( is_mouse_pressed && active_point )
		{
			active_point->setX( event->x() );
			active_point->setY( event->y() );
			for ( auto triangle : active_triangles )
			{
				triangle->update();
			}
			repaint();
			return;
		}

		active_point = nullptr;
		active_row = -1;
		active_col = -1;
		for ( int i = 0; i < row_count + 1; i++ )
		{
			for ( int j = 0; j < col_count + 1; j++ )
			{
				QPoint * p = grid->point( i, j );
				if ( gbGeo::line_length( p->x(), p->y(), event->x(), event->y() ) <= POINT_HIT_RADIUS )
				{
					active_point = p;
					active_row = i;
					active_col = j;
					break;
				}
			}
			if ( active_point ) break;
		}

		repaint();
	}

	void create_triangle_grid()
	{
		int cell_height = height() / row_count;
		int cell_width = width() / col_count;

		delete grid;
		grid = create_triangle_mesh( row_count, col_count, cell_height, cell_width, 0, 0 );

		triangle_paint_list.clear();
		for ( int i = 0; i < row_count; i++ )
		{
			for ( int j = 0; j < col_count; j++ )
			{
				triangle_paint_list.push_back( grid->upper_triangle( i, j ) );
				triangle_paint_list.push_back( grid->lower_triangle( i, j ) );
			}
		}

		full_repaint();
	}

	void full_repaint()
	{
		paint_pixmap();
		repaint();
	}

	~TriangleSurface() override
	{
		delete pixmap;
		delete polygon_painter;
		delete pixel_painter;
		delete painter;
		delete grid;
	}

public slots:

	void change_row_count( int rows )
	{
		row_count = rows;
		create_triangle_grid();
	};

	void change_column_count( int cols )
	{
		col_count = cols;
		create_triangle_grid();
	};

	void change_settings( const PainterSettings & settings )
	{
		delete polygon_painter;
		delete pixel_painter;
		pixel_painter = new AdvancedPixelPainter( painter, settings );
		polygon_painter = new QtPolygonPainter( painter, pixel_painter );
		full_repaint();
	}

private:
	void paint_pixmap()
	{
		pixmap->fill( QColor( 255, 255, 255 ) );
		painter->begin( pixmap );
		paint_triangles( &triangle_paint_list );
		painter->end();
	}

	void paint_triangles( std::list<Polygon *> * paint_list )
	{
		for ( auto triangle : *paint_list )
		{
			triangle->fill( polygon_painter );
		}

		if ( draw_borders )
		{
			for ( auto triangle : *paint_list )
			{
				triangle->draw_border( polygon_painter );
			}
		}
	}

	void find_active_triangles( int row, int col )
	{
		if ( row && col )
		{
			active_triangles.push_back( grid->lower_triangle( row - 1, col - 1 ) );
		}

		if ( row < row_count && col < col_count )
		{
			active_triangles.push_back( grid->upper_triangle( row, col ) );
		}

		if ( row && col < col_count )
		{
			active_triangles.push_back( grid->upper_triangle( row - 1, col ) );
			active_triangles.push_back( grid->lower_triangle( row - 1, col ) );
		}

		if ( row < row_count && col )
		{
			active_triangles.push_back( grid->upper_triangle( row, col - 1 ) );
			active_triangles.push_back( grid->lower_triangle( row, col - 1 ) );
		}
	}
};


#endif //TRIANGLE_PAINTER_TRIANGLESURFACE_H