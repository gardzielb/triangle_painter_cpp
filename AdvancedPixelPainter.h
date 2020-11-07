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

int compute_color_value( int color, int light, int normal_light_dot, int vr_dot, float kd, float ks, int m )
{
	int color_light_prod = light * color;
	float d = kd * (float) color_light_prod * (float) normal_light_dot;
	float s = ks * (float) color_light_prod * (float) pow( vr_dot, m );
	return (int) (d + s);
}


class AdvancedPixelPainter : public PixelPainter
{
private:
	QPainter * painter = nullptr;
	PainterSettings settings;

public:
	explicit AdvancedPixelPainter( QPainter * painter, PainterSettings settings )
			: settings( std::move( settings ) )
	{
		this->painter = painter;
	}

	void paint_pixel( int x, int y ) override
	{
		QColor color = settings.image ? settings.image->pixel( x, y ) : settings.fill_color;

//		int normal_light_dot = gbGeo::dot( settings->normal_vector, settings->light_vector );
//		gbGeo::Vector r_vector = 2 * normal_light_dot * settings->normal_vector - settings->light_vector;
//		gbGeo::Vector v_vector = gbGeo::Vector( { 0, 0, 1 } );
//		int vr_dot = gbGeo::dot( r_vector, v_vector );
//
//		int r = compute_color_value(
//				color.red(), settings->light_color.red(), normal_light_dot, vr_dot, settings->kd, settings->ks,
//				settings->m
//		);
//		int g = compute_color_value(
//				color.green(), settings->light_color.green(), normal_light_dot, vr_dot, settings->kd, settings->ks,
//				settings->m
//		);
//		int b = compute_color_value(
//				color.blue(), settings->light_color.blue(), normal_light_dot, vr_dot, settings->kd, settings->ks,
//				settings->m
//		);

//		painter->setPen( QColor( r, g, b ) );
		painter->setPen( color );
		painter->drawPoint( x, y );
	}
};


#endif //TRIANGLE_PAINTER_ADVANCEDPIXELPAINTER_H
