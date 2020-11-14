//
// Created by bartosz on 11/12/20.
//

#ifndef TRIANGLE_PAINTER_LIGHTANIMATION_H
#define TRIANGLE_PAINTER_LIGHTANIMATION_H


#include <QMutex>
#include <cmath>
#include <QObject>
#include <QTimer>
#include "TriangleSurface.h"
#include <eigen/Core>
#include <cmath>


class LightAnimation : public QObject
{
private:
	TriangleSurface & surface;
	Eigen::Vector3f * light_position = nullptr;
	QTimer timer;
	QTime time;
	int r = 0;
	const float omega = 0.00175;
	const int height_range = 100;
	const int min_height = 20;

public:
	explicit LightAnimation( TriangleSurface & surface ) : surface( surface ), timer()
	{
		r = std::min( surface.height() / 3, surface.width() / 3 );
	}

	void start( Eigen::Vector3f * light_pos )
	{
		light_position = light_pos;
		timer.setInterval( 100 );
		QObject::connect( &timer, &QTimer::timeout, this, &LightAnimation::move_light );
		time.start();
		timer.start();
	}

	void stop()
	{
		timer.stop();
		light_position = nullptr;
	}

private:
	void move_light()
	{
		int t = time.elapsed();
		light_position->x() = r * cos( t * omega ) + (float) surface.width() / 2;
		light_position->y() = r * sin( t * omega ) + (float) surface.height() / 2;
		light_position->z() = height_range * (1 + sin( t * omega )) + min_height;
		surface.full_repaint();
	}
};


#endif //TRIANGLE_PAINTER_LIGHTANIMATION_H
