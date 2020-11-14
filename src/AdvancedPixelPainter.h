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
#include <eigen/Core>


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

		Eigen::Vector3f & light_vector = settings.default_light_vector;
		if ( settings.spherical_light && settings.light_position )
		{
			light_vector = *settings.light_position - Eigen::Vector3f( x, y, 0 );
			light_vector.normalize();
		}

		Eigen::Vector3f & n_vector = settings.default_normal_vector;
		if ( settings.texture_normal_map && settings.normal_map )
		{
			n_vector = (*settings.normal_map)[x][y];
		}

		float nl_dot = n_vector.dot( light_vector );
		Eigen::Vector3f r_vector = 2 * nl_dot * n_vector - light_vector;
		Eigen::Vector3f v_vector( 0, 0, 1 );

		float a = settings.kd * nl_dot + settings.ks * pow( v_vector.dot( r_vector ), settings.m );
		int r = a * color.red() * settings.light_color.red() / COLOR_MAX;
		int g = a * color.green() * settings.light_color.green() / COLOR_MAX;
		int b = a * color.blue() * settings.light_color.blue() / COLOR_MAX;

		paint_command->execute( x, y, QColor( r, g, b ) );
	}
};


#endif //TRIANGLE_PAINTER_ADVANCEDPIXELPAINTER_H
