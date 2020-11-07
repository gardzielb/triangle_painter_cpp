//
// Created by bartosz on 11/7/20.
//

#ifndef TRIANGLE_PAINTER_PAINTERSETTINGS_H
#define TRIANGLE_PAINTER_PAINTERSETTINGS_H


#include "gbGeo.h"

struct PainterSettings
{
	int m = 1;
	float kd = 0.5;
	float ks = 0.5;
//	gbGeo::Vector normal_vector;
//	gbGeo::Vector light_vector;
	QColor light_color;
	QColor fill_color;
	QImage * image = nullptr;

	PainterSettings()
			: fill_color( 0, 255, 0 ),
			  light_color( 255, 255, 255 )
//			  normal_vector( { 0, 0, 1 } ),
//			  light_vector( { 0, 0, 1 } )
	{}
};


#endif //TRIANGLE_PAINTER_PAINTERSETTINGS_H
