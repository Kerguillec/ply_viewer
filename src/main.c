#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"

int main ( int argc, char** argv, char** envv ) {
 
//	ply_load(argv[1]);
	Tpoint* points1;
	Tpoint* points2;
	Tpoint* points3;
	
	points1 = point_malloc(1,1,1);
	debug_Pcoordinates(points1->x, points1->y, points1->z);	
	
	points2 = point_malloc(2,2,2);
	debug_Pcoordinates(points2->x, points2->y, points2->z);	

	points3 = point_malloc(5,3,2);
	debug_Pcoordinates(points3->x, points3->y, points3->z);	

	Ttriangle* triangle;
	
	triangle = triangle_malloc(points1, points2, points3);
	debug_Tcoordinates(triangle, triangle, triangle);
	return 0 ;

}
