#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"

int main ( int argc, char** argv, char** envv ) {
 
//	ply_load(argv[1]);
	Tpoint* points;

	points = point_malloc(1,1,1);
	debug_Pcoordinates(points->x, points->y, points->z);	
	

	Ttriangle* triangle;

	triangle = triangle_malloc(points, points, points);
	debug_Tcoordinates(triangle->p1, triangle->p2, triangle->p3);
	return 0 ;

}
