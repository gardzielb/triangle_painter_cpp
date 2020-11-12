//
// Created by bartosz on 11/11/20.
//

#ifndef TRIANGLE_PAINTER_BARYCENTRICPIXELPAINTER_H
#define TRIANGLE_PAINTER_BARYCENTRICPIXELPAINTER_H


#include "PixelPainter.h"
#include "PainterSettings.h"
#include "PaintCommand.h"
#include "Polygon.h"


int compute_color_value( int c1, int c2, int c3, float w1, float w2, float w3 )
{
	return (w1 * c1 + w2 * c2 + w3 * c3) / (w1 + w2 + w3);
}


class BarycentricPixelPainter : public PixelPainter
{
private:
	PaintCommand * paint_command = nullptr;
	const Polygon * triangle = nullptr;
	QRgb * pixels = nullptr;
	int img_height = 0;

public:
	explicit BarycentricPixelPainter( PaintCommand * paint_command, const Polygon * triangle, QRgb * pixels,
									  int img_height ) : img_height( img_height )
	{
		this->paint_command = paint_command;
		this->triangle = triangle;
		this->pixels = pixels;
	}

	void paint_pixel( int x, int y ) override
	{
		if ( triangle->has_vertex( x, y ) ) return;

		auto weights = triangle->barycentric_coordinates( x, y );
		float w1 = std::get<0>( weights );
		float w2 = std::get<1>( weights );
		float w3 = std::get<2>( weights );

		const std::vector<QPoint *> vertices = triangle->get_vertices();
		std::vector<QColor> colors( vertices.size() );
		std::transform(
				vertices.cbegin(), vertices.cend(), colors.begin(),
				[ = ]( const QPoint * v ) { return QColor( pixels[v->x() + img_height * v->y()] ); }
		);

		int r = compute_color_value( colors[0].red(), colors[1].red(), colors[2].red(), w1, w2, w3 );
		int g = compute_color_value( colors[0].green(), colors[1].green(), colors[2].green(), w1, w2, w3 );
		int b = compute_color_value( colors[0].blue(), colors[1].blue(), colors[2].blue(), w1, w2, w3 );

		paint_command->execute( x, y, QColor( r, g, b ) );
	}
};


#endif //TRIANGLE_PAINTER_BARYCENTRICPIXELPAINTER_H
