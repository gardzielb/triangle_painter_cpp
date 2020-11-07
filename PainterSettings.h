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
	gbGeo::Vector * normal_vector = new gbGeo::Vector( { 0, 0, 1 } );
	gbGeo::Vector * light_vector = new gbGeo::Vector( { 0, 0, 1 } );
	QColor * light_color = new QColor( 255, 255, 255 );
	QColor * fill_color = new QColor( 0, 255, 0 );
	QImage * image = nullptr;
};


#endif //TRIANGLE_PAINTER_PAINTERSETTINGS_H
