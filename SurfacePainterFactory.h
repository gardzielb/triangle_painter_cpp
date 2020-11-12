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

public:
	ImageSurfacePainterFactory( int width, int height ) : img_height( height )
	{
		pixels = new QRgb[width * height];
		image = new QImage( (uchar *) pixels, width, height, QImage::Format_ARGB32 );
	}

	SurfacePainter * create_painter( const PainterSettings & settings ) override
	{
		delete surface_painter;
		delete pixel_painter;
		delete paint_command;
		paint_command = new ImagePixelPaintCommand( pixels, img_height );
		pixel_painter = new AdvancedPixelPainter( paint_command, settings );

		if ( settings.vertex_interpolation )
		{
			surface_painter = new SurfacePainter(
					image, new InterpolationFillTriangleStrategy( pixel_painter, paint_command, pixels, img_height )
			);
		} else
		{
			surface_painter = new SurfacePainter( image, new PreciseFillTriangleStrategy( pixel_painter ) );
		}

		return surface_painter;
	}

	~ImageSurfacePainterFactory() override
	{
		delete image;
		delete[] pixels;
	}
};


#endif //TRIANGLE_PAINTER_SURFACEPAINTERFACTORY_H
