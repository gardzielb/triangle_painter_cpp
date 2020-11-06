//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_POLYGON_H
#define TRIANGLE_PAINTER_POLYGON_H


#include <utility>
#include <vector>
#include <QtCore/QPoint>
#include <QtGui/QPainterPath>
#include "PolygonPainter.h"
#include "painting.h"

class Polygon
{
private:
	std::vector<QPoint *> vertices;

public:
	explicit Polygon( std::vector<QPoint *> vertices ) : vertices( std::move( vertices ) )
	{
		update();
	}

	void draw_border( PolygonPainter * painter )
	{
		for ( int i = 0; i < vertices.size(); i++ )
		{
			int i2 = (i + 1) % vertices.size();
			QPoint * p1 = vertices[i];
			QPoint * p2 = vertices[i2];
			painter->draw_line( p1->x(), p1->y(), p2->x(), p2->y() );
		}
	}

	void fill( PolygonPainter * painter )
	{
		std::vector<int> indexes( { 0, 1, 2 } );
		fill_polygon( vertices, indexes, painter );
	}

	void update()
	{
		std::sort(
				vertices.begin(), vertices.end(),
				[]( const QPoint * p1, const QPoint * p2 ) { return p1->y() <= p2->y(); }
		);
	}

	bool operator==( const Polygon & other )
	{
		for ( int i = 0; i < vertices.size(); i++ )
		{
			if ( vertices[i] != other.vertices[i] ) return false;
		}
		return true;
	}
};


class TriangleGrid
{
private:
	int cols;
	std::vector<Polygon *> triangles_upper;
	std::vector<Polygon *> triangles_lower;
	std::vector<QPoint *> points;

public:
	TriangleGrid( int cols, std::vector<QPoint *> points, std::vector<Polygon *> triangles_upper,
				  std::vector<Polygon *> triangles_lower )
			: cols( cols ), points( std::move( points ) ),
			  triangles_lower( std::move( triangles_lower ) ),
			  triangles_upper( std::move( triangles_upper ) )
	{}

	Polygon * upper_triangle( int row, int col )
	{
		return triangles_upper[triangle_index( row, col )];
	}

	Polygon * lower_triangle( int row, int col )
	{
		return triangles_lower[triangle_index( row, col )];
	}

	QPoint * point( int row, int col )
	{
		return points[point_index( row, col )];
	}

	~TriangleGrid()
	{
		for ( int i = 0; i < triangles_upper.size(); i++ )
		{
			delete triangles_upper[i];
			delete triangles_lower[i];
		}
		for ( auto point : points )
		{
			delete point;
		}
	}

private:
	int triangle_index( int row, int col ) const
	{
		return row * cols + col;
	}

	int point_index( int row, int col ) const
	{
		return row * (cols + 1) + col;
	}
};


TriangleGrid * create_triangle_mesh( int n, int m, int cell_height, int cell_width, int v_margin, int h_margin )
{
	std::vector<QPoint *> points;
	std::vector<Polygon *> triangles_up;
	std::vector<Polygon *> triangles_low;

	for ( int i = 0; i < n + 1; i++ )
	{
		for ( int j = 0; j < m + 1; j++ )
		{
			auto p = new QPoint( h_margin + j * cell_width, v_margin + i * cell_height );
			points.push_back( p );
		}
	}

	auto index = [ m ]( int i, int j ) { return i * (m + 1) + j; };

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < m; j++ )
		{
			auto t1 = new Polygon( std::vector<QPoint *>(
					{ points[index( i, j )], points[index( i + 1, j )], points[index( i, j + 1 )] }
			) );
			auto t2 = new Polygon( std::vector<QPoint *>(
					{ points[index( i + 1, j + 1 )], points[index( i + 1, j )], points[index( i, j + 1 )] }
			) );
			triangles_up.push_back( t1 );
			triangles_low.push_back( t2 );
		}
	}

	return new TriangleGrid( m, points, triangles_up, triangles_low );
}


#endif //TRIANGLE_PAINTER_POLYGON_H
