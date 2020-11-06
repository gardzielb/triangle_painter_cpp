//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_POLYGONPAINTER_H
#define TRIANGLE_PAINTER_POLYGONPAINTER_H


class PolygonPainter
{
public:
	virtual void fill_pixel( int x, int y ) = 0;

	virtual void draw_active_point( int x, int y, int radius ) = 0;

	virtual void draw_line( int x1, int y1, int x2, int y2 ) = 0;

	virtual ~PolygonPainter() = default;
};


#endif //TRIANGLE_PAINTER_POLYGONPAINTER_H
