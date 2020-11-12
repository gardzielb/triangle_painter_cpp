//
// Created by bartosz on 11/11/20.
//

#ifndef TRIANGLE_PAINTER_FILLTRIANGLESTRATEGY_H
#define TRIANGLE_PAINTER_FILLTRIANGLESTRATEGY_H


#include "Polygon.h"
#include "PainterSettings.h"
#include "AdvancedPixelPainter.h"
#include "BarycentricPixelPainter.h"


class FillTriangleStrategy
{
public:
	virtual void fill_triangle( const Polygon * triangle ) = 0;

	virtual ~FillTriangleStrategy() = default;
};


class PreciseFillTriangleStrategy : public FillTriangleStrategy
{
private:
	PixelPainter * painter = nullptr;

public:
	explicit PreciseFillTriangleStrategy( PixelPainter * painter )
	{
		this->painter = painter;
	}

	void fill_triangle( const Polygon * triangle ) override
	{
		triangle->fill( painter );
	}
};


class InterpolationFillTriangleStrategy : public FillTriangleStrategy
{
private:
	PixelPainter * vertex_painter = nullptr;
	QRgb * pixels = nullptr;
	int img_height = 0;
	PaintCommand * interior_paint_command = nullptr;

public:
	explicit InterpolationFillTriangleStrategy( PixelPainter * vertex_painter, PaintCommand * interior_paint_command,
												QRgb * pixels, int img_height ) : img_height( img_height )
	{
		this->vertex_painter = vertex_painter;
		this->pixels = pixels;
		this->interior_paint_command = interior_paint_command;
	}

	void fill_triangle( const Polygon * triangle ) override
	{
		for ( auto v : triangle->get_vertices() )
		{
			vertex_painter->paint_pixel( v->x(), v->y() );
		}

		auto interior_painter = new BarycentricPixelPainter( interior_paint_command, triangle, pixels, img_height );
		triangle->fill( interior_painter );
		delete interior_painter;
	}
};


#endif //TRIANGLE_PAINTER_FILLTRIANGLESTRATEGY_H
