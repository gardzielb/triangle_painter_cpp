//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PIXELPAINTER_H
#define TRIANGLE_PAINTER_PIXELPAINTER_H


class PixelPainter
{
public:
	virtual void paint_pixel( int x, int y ) = 0;

	virtual ~PixelPainter() = default;
};


#endif //TRIANGLE_PAINTER_PIXELPAINTER_H
