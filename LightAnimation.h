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


class LightAnimation : public QObject
{
private:
	TriangleSurface & surface;
	gbGeo::Vector3 * light_position = nullptr;
	QTimer timer;
	QTime time;
	int r = 0;

public:
	explicit LightAnimation( TriangleSurface & surface ) : surface( surface ), timer()
	{}

	void start( gbGeo::Vector3 * light_pos, int radius )
	{
		r = radius;
		light_position = light_pos;
		timer.setInterval( 1000 );
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
		float x = r * cos( t * 0.1 ) + (float) surface.width() / 2;
		float y = r * sin( t * 0.1 ) + (float) surface.height() / 2;
		light_position->setX( x );
		light_position->setY( y );
		light_position->setZ( t % 20 );
		surface.full_repaint();
	}
};


#endif //TRIANGLE_PAINTER_LIGHTANIMATION_H
