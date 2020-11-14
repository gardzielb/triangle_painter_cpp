//
// Created by bartosz on 11/7/20.
//

#include <cmath>
#include "gbGeo.h"

float gbGeo::line_length( int x1, int y1, int x2, int y2 )
{
	return sqrt( pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ) );
}

std::pair<float, int> gbGeo::line_equation( int x1, int y1, int x2, int y2 )
{
	int dx = x1 - x2;
	if ( !dx ) return std::make_pair( 0, 0 );

	float a = (float) (y1 - y2) / (float) (x1 - x2);
	int b = y1 - a * x1;
	return std::make_pair( a, b );
}
