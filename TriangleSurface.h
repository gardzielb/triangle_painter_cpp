//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_TRIANGLESURFACE_H
#define TRIANGLE_PAINTER_TRIANGLESURFACE_H


#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <utility>
#include <QtCore/QTime>
#include "AdvancedPixelPainter.h"
#include "Polygon.h"
#include "BarycentricPixelPainter.h"
#include "SurfacePainter.h"
#include "FillTriangleStrategy.h"
#include "SurfacePainterFactory.h"

class TriangleSurface : public QWidget
{
public:
	const static int DEFAULT_WIDTH = 800;
	const static int DEFAULT_HEIGHT = 800;

private:
	SurfacePainter * main_painter = nullptr;
	SurfacePainter * background_painter = nullptr;
	SurfacePainterFactory * main_painter_factory = nullptr;
	SurfacePainterFactory * background_painter_factory = nullptr;

	int row_count;
	int col_count;
	TriangleGrid * grid = nullptr;

	QPoint * active_point = nullptr;
	int active_row = -1;
	int active_col = -1;
	std::list<Polygon *> active_triangles;
	std::list<Polygon *> triangle_paint_list;
	bool is_mouse_pressed = false;

	const int POINT_HIT_RADIUS = 5;

public:
	TriangleSurface( int row_count, int col_count )
			: row_count( row_count ), col_count( col_count )
	{
		setFixedSize( DEFAULT_WIDTH, DEFAULT_HEIGHT );

		main_painter_factory = new ImageSurfacePainterFactory( width(), height() );
		background_painter_factory = new ImageSurfacePainterFactory( width(), height() );
		PainterSettings settings;
		main_painter = main_painter_factory->create_painter( settings );
		background_painter = background_painter_factory->create_painter( settings );

		create_triangle_grid();
		setMouseTracking( true );
	}

	void paintEvent( QPaintEvent * event ) override
	{
		background_painter->paint_on_device( main_painter->device() );
		main_painter->paint_triangles( active_triangles );

		if ( active_point )
		{
			main_painter->paint_active_point( active_point->x(), active_point->y(), POINT_HIT_RADIUS );
		}

		main_painter->paint_on_device( this );
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

		background_painter->paint_triangles( triangle_paint_list );
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

		background_painter->paint_triangles( triangle_paint_list );
		repaint();
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

		background_painter->paint_triangles( triangle_paint_list );
		repaint();
	}

	~TriangleSurface() override
	{
		delete main_painter_factory;
		delete background_painter_factory;
		delete main_painter;
		delete background_painter;
		delete grid;
	}

public slots:

	void reset_grid( int rows, int cols )
	{
		row_count = rows;
		col_count = cols;
		create_triangle_grid();
	};

	void change_settings( const PainterSettings & settings )
	{
		main_painter = main_painter_factory->create_painter( settings );
		background_painter = background_painter_factory->create_painter( settings );
		background_painter->paint_triangles( triangle_paint_list );
		repaint();
	}

private:
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