//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_GBGEO_H
#define TRIANGLE_PAINTER_GBGEO_H


#include <vector>


namespace gbGeo
{
	float line_length( int x1, int y1, int x2, int y2 );

	std::pair<float, int> line_equation( int x1, int y1, int x2, int y2 );
}


#endif //TRIANGLE_PAINTER_GBGEO_H
