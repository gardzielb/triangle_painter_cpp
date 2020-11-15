//
// Created by bartosz on 11/11/20.
//

#ifndef TRIANGLE_PAINTER_SURFACEPAINTERFACTORY_H
#define TRIANGLE_PAINTER_SURFACEPAINTERFACTORY_H


#include "SurfacePainter.h"

class SurfacePainterFactory
{
public:
	virtual SurfacePainter * create_painter( const PainterSettings & settings ) = 0;

	virtual ~SurfacePainterFactory() = default;
};


class ImageSurfacePainterFactory : public SurfacePainterFactory
{
private:
	int img_height = 0;
	QRgb * pixels = nullptr;
	QImage * image = nullptr;
	PixelPainter * pixel_painter = nullptr;
	PaintCommand * paint_command = nullptr;
	SurfacePainter * surface_painter = nullptr;
	FillTriangleStrategy * fill_strategy = nullptr;

public:
	ImageSurfacePainterFactory( int width, int height ) : img_height( height )
	{
		pixels = new QRgb[width * height];
		image = new QImage( (uchar *) pixels, width, height, QImage::Format_ARGB32 );
	}

	SurfacePainter * create_painter( const PainterSettings & settings ) override
	{
		cleanup();
		paint_command = new ImagePixelPaintCommand( pixels, img_height );
		pixel_painter = new AdvancedPixelPainter( paint_command, settings );

		if ( settings.vertex_interpolation )
		{
			fill_strategy = new InterpolationFillTriangleStrategy( pixel_painter, paint_command, pixels, img_height );
		}
		else
		{
			fill_strategy = new PreciseFillTriangleStrategy( pixel_painter );
		}

		return new SurfacePainter( image, fill_strategy, settings.draw_borders );
	}

	~ImageSurfacePainterFactory() override
	{
		cleanup();
		delete image;
		delete[] pixels;
	}

private:
	void cleanup()
	{
		delete surface_painter;
		delete pixel_painter;
		delete paint_command;
		delete fill_strategy;
	}
};


#endif //TRIANGLE_PAINTER_SURFACEPAINTERFACTORY_H
