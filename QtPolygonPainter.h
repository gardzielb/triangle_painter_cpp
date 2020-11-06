//
// Created by bartosz on 11/4/20.
//

#ifndef TRIANGLE_PAINTER_QTPOLYGONPAINTER_H
#define TRIANGLE_PAINTER_QTPOLYGONPAINTER_H


#include <QtGui/QPainter>
#include "PolygonPainter.h"
#include "PixelPainter.h"

class QtPolygonPainter : public PolygonPainter
{
private:
	QPainter * painter = nullptr;
	PixelPainter * pixel_painter = nullptr;
	const QBrush active_brush;
	const QColor stroke_pen;

public:
	explicit QtPolygonPainter( QPainter * painter, PixelPainter * pixel_painter )
			: active_brush( QColor( 120, 255, 120 ) ),
			  stroke_pen( 0, 0, 255 )
	{
		this->painter = painter;
		this->pixel_painter = pixel_painter;
	}

	void draw_active_point( int x, int y, int radius ) override
	{
		painter->setBrush( active_brush );
		painter->setPen( Qt::NoPen );
		painter->drawEllipse( QPoint( x, y ), radius, radius );
	}

	void draw_line( int x1, int y1, int x2, int y2 ) override
	{
		painter->setPen( stroke_pen );
		painter->drawLine( x1, y1, x2, y2 );
	}

	void fill_pixel( int x, int y ) override
	{
		pixel_painter->paint_pixel( x, y );
	}
};


#endif //TRIANGLE_PAINTER_QTPOLYGONPAINTER_H
