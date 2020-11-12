//
// Created by bartosz on 11/11/20.
//

#ifndef TRIANGLE_PAINTER_SURFACEPAINTER_H
#define TRIANGLE_PAINTER_SURFACEPAINTER_H

#include <QPainter>
#include <QPaintDevice>
#include "Polygon.h"
#include "PixelPainter.h"
#include "PaintCommand.h"
#include "PainterSettings.h"
#include "FillTriangleStrategy.h"


class SurfacePainter
{
private:
	FillTriangleStrategy * fill_strategy = nullptr;
	QPainter * painter = new QPainter();
	QImage * image = nullptr;

	const QBrush active_brush;
	const QColor stroke_pen;

public:
	explicit SurfacePainter( QImage * image, FillTriangleStrategy * fill_strategy )
			: active_brush( QColor( 120, 255, 120 ) ), stroke_pen( 0, 0, 0 )
	{
		this->fill_strategy = fill_strategy;
		this->image = image;
	}

	QPaintDevice * device()
	{
		return image;
	}

	void paint_on_device( QPaintDevice * device )
	{
		painter->begin( device );
		painter->drawImage( 0, 0, *image );
		painter->end();
	}

	void paint_triangles( const std::list<Polygon *> & triangles )
	{
		fill_triangles( triangles );
		draw_borders( triangles );
	}

	void paint_active_point( int x, int y, int radius )
	{
		painter->begin( image );
		painter->setBrush( active_brush );
		painter->setPen( Qt::NoPen );
		painter->drawEllipse( QPoint( x, y ), radius, radius );
		painter->end();
	}

	~SurfacePainter()
	{
		delete painter;
	}

private:
	void draw_borders( const std::list<Polygon *> & triangles )
	{
		painter->begin( image );
		painter->setPen( stroke_pen );
		for ( auto triangle : triangles )
		{
			triangle->draw_border( painter );
		}
		painter->end();
	}

	void fill_triangles( const std::list<Polygon *> & triangles )
	{
		for ( auto triangle : triangles )
		{
			fill_strategy->fill_triangle( triangle );
		}
	}
};


#endif //TRIANGLE_PAINTER_SURFACEPAINTER_H
