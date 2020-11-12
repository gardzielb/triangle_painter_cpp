//
// Created by bartosz on 11/7/20.
//

#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#include "gbGeo.h"

using namespace gbGeo;

Vector::Vector( std::vector<float> in_array ) : array( std::move( in_array ) )
{}

int Vector::size() const
{
	return array.size();
}

auto Vector::first() const
{
	return array.cbegin();
}

auto Vector::last() const
{
	return array.cend();
}

auto Vector::first()
{
	return array.begin();
}

auto Vector::last()
{
	return array.end();
}

float Vector::norm() const
{
	return sqrt( std::inner_product( first(), last(), first(), 0.0f ) );
}

void Vector::normalize()
{
	float norm = this->norm();
	std::transform( array.begin(), array.end(), array.begin(), [ = ]( float x ) { return x / norm; } );
}

Vector Vector::normalized() const
{
	std::vector<float> nv( this->size() );
	float norm = this->norm();
	std::transform( this->first(), this->last(), nv.begin(), [ = ]( float x ) { return x / norm; } );
	return Vector( nv );
}

std::string Vector::to_str()
{
	std::string str = "[";
	for ( auto x : array )
	{
		str.append( std::to_string( x ) );
		str.append( "," );
	}
	str.erase( str.end() - 1 );
	str.append( "]" );
	return str;
}

Vector gbGeo::operator*( float a, const Vector & v )
{
	std::vector<float> product( v.size() );
	std::transform( v.first(), v.last(), product.begin(), [ a ]( const float x ) { return a * x; } );
	return Vector( product );
}

Vector gbGeo::operator-( const Vector & v1, const Vector & v2 )
{
	std::vector<float> out( v1.size() );
	std::transform( v1.first(), v1.last(), v2.first(), out.begin(), std::minus<>() );
	return Vector( out );
}

float gbGeo::dot( Vector v1, Vector v2 )
{
	return std::inner_product( v1.first(), v1.last(), v2.first(), 0.0f );
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

Vector3::Vector3( float x, float y, float z ) : Vector( { x, y, z } )
{}

float Vector3::x()
{
	return array[0];
}

void Vector3::setX( float x )
{
	array[0] = x;
}

float Vector3::y()
{
	return array[0];
}

void Vector3::setY( float y )
{
	array[1] = y;
}

float Vector3::z()
{
	return array[0];
}

void Vector3::setZ( float z )
{
	array[2] = z;
}