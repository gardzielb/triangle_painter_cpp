//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PAINTING_H
#define TRIANGLE_PAINTER_PAINTING_H

#include <QtCore/QPoint>
#include <list>
#include "gbGeo.h"
#include "PolygonPainter.h"

struct ActiveEdge
{
	int y_max;
	float x;
	float delta_x;

	ActiveEdge( QPoint & p1, QPoint & p2 )
	{
		y_max = p2.y();
		x = (float) p1.x();
		float a = gbGeo::line_equation( p1.x(), p1.y(), p2.x(), p2.y() ).first;
		delta_x = a ? 1 / a : 0;
	}

	bool operator==( const ActiveEdge & other ) const
	{
		return (y_max == other.y_max && x == other.x && delta_x == other.delta_x);
	}
};

void update_aet( std::vector<ActiveEdge> & aet, int y )
{
	auto removed_it = std::remove_if( aet.begin(), aet.end(), [ y ]( const ActiveEdge & e ) { return e.y_max < y; } );
	aet.erase( removed_it, aet.end() );
	for ( auto & e : aet )
	{
		e.x += e.delta_x;
	}
	std::sort( aet.begin(), aet.end(), []( const ActiveEdge & e1, const ActiveEdge & e2 ) { return e1.x <= e2.x; } );
}

std::pair<QPoint, QPoint> find_neighbors( int index, std::vector<QPoint *> & vertices )
{
	int i_prev = index ? (index - 1) : vertices.size() - 1;
	int i_next = (index + 1) % vertices.size();
	return std::make_pair( *vertices[i_prev], *vertices[i_next] );
}

void paint_scan_line( int x1, int x2, int y, PolygonPainter * painter )
{
	for ( int x = x1; x < x2 + 1; x++ )
	{
		painter->fill_pixel( x, y );
	}
}

void fill_polygon( std::vector<QPoint *> & vertices, std::vector<int> & indexes, PolygonPainter * painter )
{
	int v_count = vertices.size();
	std::vector<ActiveEdge> aet;

	for ( int y = vertices[0]->y(); y < vertices[v_count - 1]->y() + 1; y++ )
	{
		for ( int i : indexes )
		{
			if ( vertices[i]->y() >= y ) break;
			if ( vertices[i]->y() == y - 1 )
			{
				auto neighbors = find_neighbors( i, vertices );
				if ( neighbors.first.y() > vertices[i]->y() )
				{
					aet.emplace_back( *vertices[i], neighbors.first );
				}
				if ( neighbors.second.y() > vertices[i]->y() )
				{
					aet.emplace_back( *vertices[i], neighbors.second );
				}
			}
		}

		update_aet( aet, y );
		for ( int j = 0; j < aet.size() / 2; j++ )
		{
			int x1 = aet[2 * j].x, x2 = aet[2 * j + 1].x;
			paint_scan_line( x1, x2, y, painter );
//			printf( "Painting scan line: [(%d, %d), (%d, %d)]\n", x1, y, x2, y );
		}
	}
}

#endif //TRIANGLE_PAINTER_PAINTING_H
