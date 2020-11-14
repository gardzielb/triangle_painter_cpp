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


class LightAnimation : public QObject
{
private:
	TriangleSurface & surface;
//	gbGeo::Vector3 * light_position = nullptr;
	Eigen::Vector3f * light_position = nullptr;
	QTimer timer;
	QTime time;
	int r = 0;
	float omega = 0.00175;

public:
	explicit LightAnimation( TriangleSurface & surface ) : surface( surface ), timer()
	{}

	void start( Eigen::Vector3f * light_pos, int radius )
	{
		r = radius;
		light_position = light_pos;
		timer.setInterval( 200 );
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
		light_position->z() = t % 20;
		surface.full_repaint();
	}
};


#endif //TRIANGLE_PAINTER_LIGHTANIMATION_H
