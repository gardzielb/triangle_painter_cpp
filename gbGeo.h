//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_GBGEO_H
#define TRIANGLE_PAINTER_GBGEO_H


#include <utility>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>


namespace gbGeo
{
	class Vector
	{
	private:
		std::vector<int> * array;

	public:
		Vector( std::initializer_list<int> in_array )
		{
			array = new std::vector<int>( in_array );
		}

		explicit Vector( std::vector<int> in_array )
		{
			array = new std::vector<int>( std::move( in_array ) );
		}

		int size() const
		{
			return array->size();
		}

		auto first() const
		{
			return array->cbegin();
		}

		auto last() const
		{
			return array->cend();
		}

		auto first()
		{
			return array->begin();
		}

		auto last()
		{
			return array->end();
		}

		~Vector()
		{
			delete array;
		}
	};

	Vector operator*( int a, const Vector & v )
	{
		std::vector<int> product( v.size() );
		std::transform( v.first(), v.last(), product.begin(), [ a ]( const int x ) { return a * x; } );
		return Vector( product );
	}

	Vector operator-( const Vector & v1, const Vector & v2 )
	{
		std::vector<int> out( v1.size() );
		std::transform( v1.first(), v1.last(), v2.first(), out.begin(), std::minus<>() );
		return Vector( out );
	}

	int dot( Vector v1, Vector v2 )
	{
		return std::inner_product( v1.first(), v1.last(), v2.first(), 0 );
	}

	float line_length( int x1, int y1, int x2, int y2 )
	{
		return sqrt( pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ) );
	}

	std::pair<float, int> line_equation( int x1, int y1, int x2, int y2 )
	{
		int dx = x1 - x2;
		if ( !dx ) return std::make_pair( 0, 0 );

		float a = (float) (y1 - y2) / (float) (x1 - x2);
		int b = y1 - a * x1;
		return std::make_pair( a, b );
	}
}


#endif //TRIANGLE_PAINTER_GBGEO_H
