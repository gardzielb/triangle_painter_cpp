//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_GBGEO_H
#define TRIANGLE_PAINTER_GBGEO_H


#include <vector>


namespace gbGeo
{
	class Vector
	{
	protected:
		std::vector<float> array;

	public:
		explicit Vector( std::vector<float> in_array );

		float norm() const;

		void normalize();

		Vector normalized() const;

		int size() const;

		auto first() const;

		auto last() const;

		auto first();

		auto last();

		std::string to_str();
	};

	class Vector3 : public Vector
	{
	public:
		Vector3( float x, float y, float z );

		float x();

		void setX( float x );

		float y();

		void setY( float y );

		float z();

		void setZ( float z );
	};

	Vector operator*( float a, const Vector & v );

	Vector operator-( const Vector & v1, const Vector & v2 );

	float dot( Vector v1, Vector v2 );

	float line_length( int x1, int y1, int x2, int y2 );

	std::pair<float, int> line_equation( int x1, int y1, int x2, int y2 );
}


#endif //TRIANGLE_PAINTER_GBGEO_H
