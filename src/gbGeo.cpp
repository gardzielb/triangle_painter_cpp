//
// Created by bartosz on 11/7/20.
//

#include <cmath>
#include "gbGeo.h"


gbGeo::Vector3::Vector3( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float gbGeo::Vector3::norm() const
{
	return std::sqrt( x * x + y * y + z * z );
}

void gbGeo::Vector3::normalize()
{
	float n = norm();
	x /= n;
	y /= n;
	z /= n;
}

float gbGeo::Vector3::dot( const Vector3 & v ) const
{
	return x * v.x + y * v.y + z * v.z;
}

float & gbGeo::Vector3::X()
{ return x; }

float & gbGeo::Vector3::Y()
{ return y; }

float & gbGeo::Vector3::Z()
{ return z; }

float gbGeo::Vector3::X() const
{ return x; }

float gbGeo::Vector3::Y() const
{ return y; }

float gbGeo::Vector3::Z() const
{ return z; }

gbGeo::Vector3 gbGeo::operator-( const Vector3 & u, const Vector3 & v )
{
	return { u.X() - v.X(), u.Y() - v.Y(), u.Z() - v.Z() };
}

gbGeo::Vector3 gbGeo::operator*( float a, const Vector3 & v )
{
	return { a * v.X(), a * v.Y(), a * v.Z() };
}

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
