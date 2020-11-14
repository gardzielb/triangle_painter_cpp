//
// Created by bartosz on 11/7/20.
//

#ifndef TRIANGLE_PAINTER_PAINTERSETTINGS_H
#define TRIANGLE_PAINTER_PAINTERSETTINGS_H


#include <QtGui/QImage>
#include <QtCore/QMutex>
#include <eigen/Core>
#include "gbGeo.h"


class NormalMap
{
private:
//	Eigen::Vector3f * map = nullptr;
	gbGeo::Vector3 * map = nullptr;
	int height = 0;

public:
	explicit NormalMap( const QImage & image )
	{
//		map = new Eigen::Vector3f[image.width() * image.height()];
		map = new gbGeo::Vector3[image.width() * image.height()];
		height = image.height();

		for ( int x = 0; x < image.width(); x++ )
		{
			for ( int y = 0; y < image.height(); y++ )
			{
				QColor color = image.pixel( x, y );
				gbGeo::Vector3 v( color.red() - 127, color.green() - 127, color.blue() / 2 );
				v.normalize();
				map[x * height + y] = v;
			}
		}
	}

//	Eigen::Vector3f & operator()( int x, int y )
	gbGeo::Vector3 & operator()( int x, int y )
	{
		return map[x * height + y];
	}

	~NormalMap()
	{
		delete[] map;
	}
};


struct PainterSettings
{
	int m = 1;
	float kd = 0.5;
	float ks = 0.5;

	bool spiral_light = false;
	gbGeo::Vector3 * light_position = nullptr;
//	Eigen::Vector3f * light_position = nullptr;

//	Eigen::Vector3f default_light_vector;
	gbGeo::Vector3 default_light_vector;
	QColor light_color;

	bool texture_paint = false;
	QImage * image = nullptr;
	QColor fill_color;

	bool texture_normal_map = false;
	NormalMap * normal_map = nullptr;
	gbGeo::Vector3 default_normal_vector;
//	Eigen::Vector3f default_normal_vector;

	bool vertex_interpolation = false;

	PainterSettings()
			: fill_color( 0, 255, 0 ),
			  light_color( 255, 255, 255 ),
			  default_normal_vector( { 0, 0, 1 } ),
			  default_light_vector( { 0, 0, 1 } )
	{}
};


#endif //TRIANGLE_PAINTER_PAINTERSETTINGS_H
