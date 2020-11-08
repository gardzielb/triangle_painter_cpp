//
// Created by bartosz on 11/7/20.
//

#ifndef TRIANGLE_PAINTER_PAINTERSETTINGS_H
#define TRIANGLE_PAINTER_PAINTERSETTINGS_H


#include "gbGeo.h"


class NormalMap
{
private:
	std::vector<std::vector<gbGeo::Vector>> map;

public:
	explicit NormalMap( const QImage & image )
	{
		for ( int x = 0; x < image.width(); x++ )
		{
			std::vector<gbGeo::Vector> column;
			for ( int y = 0; y < image.height(); y++ )
			{
				QColor color = image.pixel( x, y );
				gbGeo::Vector v( { (float) color.red() - 127, (float) color.green() - 127, (float) color.blue() / 2 } );
				column.emplace_back( v.normalized() );
			}
			map.push_back( column );
		}
	}

	std::vector<gbGeo::Vector> & operator[]( int i )
	{
		return map[i];
	}
};


struct PainterSettings
{
	int m = 1;
	float kd = 0.5;
	float ks = 0.5;
	bool spherical_light = false;
	gbGeo::Vector default_light_vector;
	QColor light_color;
	bool texture_paint = false;
	QImage * image = nullptr;
	QColor fill_color;
	bool texture_normal_map = false;
	NormalMap * normal_map = nullptr;
	gbGeo::Vector default_normal_vector;
	bool vertex_interpolation = false;

	PainterSettings()
			: fill_color( 0, 255, 0 ),
			  light_color( 255, 255, 255 ),
			  default_normal_vector( { 0, 0, 1 } ),
			  default_light_vector( { 0, 0, 1 } )
	{}
};


#endif //TRIANGLE_PAINTER_PAINTERSETTINGS_H
