//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_GBGEO_H
#define TRIANGLE_PAINTER_GBGEO_H


#include <cmath>
#include <vector>


namespace gbGeo
{
	class Vector3
	{
	private:
		float x = 0, y = 0, z = 0;

	public:
		Vector3() = default;

		Vector3( float x, float y, float z );

		float norm() const;

		void normalize();

		float & X();

		float & Y();

		float & Z();

		float X() const;

		float Y() const;

		float Z() const;

		float dot( const Vector3 & v ) const;
	};

	Vector3 operator-( const Vector3 & u, const Vector3 & v );

	Vector3 operator*( float a, const Vector3 & v );

	float line_length( int x1, int y1, int x2, int y2 );

	std::pair<float, int> line_equation( int x1, int y1, int x2, int y2 );
}


#endif //TRIANGLE_PAINTER_GBGEO_H
