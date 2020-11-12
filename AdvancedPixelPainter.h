//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_ADVANCEDPIXELPAINTER_H
#define TRIANGLE_PAINTER_ADVANCEDPIXELPAINTER_H


#include <QtGui/QPainter>
#include <cmath>
#include <utility>
#include "PixelPainter.h"
#include "PainterSettings.h"
#include "PaintCommand.h"

int compute_color_value( int color, int light, float normal_light_dot, float vr_dot, float kd, float ks, int m )
{
	int color_light_prod = light * color;
	float d = kd * (float) color_light_prod * (float) normal_light_dot;
	float s = ks * (float) color_light_prod * (float) pow( vr_dot, m );
	return (int) (d + s);
}


class AdvancedPixelPainter : public PixelPainter
{
private:
	PaintCommand * paint_command = nullptr;
	PainterSettings settings;
	const int COLOR_MAX = 255;

public:
	explicit AdvancedPixelPainter( PaintCommand * paint_command, PainterSettings settings )
			: settings( std::move( settings ) )
	{
		this->paint_command = paint_command;
	}

	void paint_pixel( int x, int y ) override
	{
		QColor color = (settings.texture_paint && settings.image) ? settings.image->pixel( x, y ) : settings.fill_color;
		gbGeo::Vector & n_vector = settings.default_normal_vector;
		if ( settings.texture_normal_map && settings.normal_map )
		{
			n_vector = (*settings.normal_map)[x][y];
		}

		float normal_light_dot = gbGeo::dot( n_vector, settings.default_light_vector );
		gbGeo::Vector r_vector = 2 * normal_light_dot * n_vector - settings.default_light_vector;
		gbGeo::Vector v_vector = gbGeo::Vector( { 0, 0, 1 } );
		float vr_dot = gbGeo::dot( v_vector, r_vector );

		int r = compute_color_value(
				color.red(), settings.light_color.red(), normal_light_dot, vr_dot, settings.kd, settings.ks,
				settings.m
		);
		int g = compute_color_value(
				color.green(), settings.light_color.green(), normal_light_dot, vr_dot, settings.kd, settings.ks,
				settings.m
		);
		int b = compute_color_value(
				color.blue(), settings.light_color.blue(), normal_light_dot, vr_dot, settings.kd, settings.ks,
				settings.m
		);

		QColor pixel_color( r / COLOR_MAX, g / COLOR_MAX, b / COLOR_MAX );
		paint_command->execute( x, y, pixel_color );
	}
};


#endif //TRIANGLE_PAINTER_ADVANCEDPIXELPAINTER_H
