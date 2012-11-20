#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"
#include "model.h"
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
	debug_Tcoordinates(triangle);
	
	
	Tmodel* test;
	
	test = model_malloc() ;
	
	int i;	
	// How To use model_add_point & model_add_triangle:
	for(i=0; i<10; i++)
	{
		model_add_point(test, 1, 2, 3);
		model_add_point(test, 654, 12, 13);
		model_add_point(test, 11, 521, 81);
	}

	for(i=0; i<10; i++)
		model_add_triangle(test, test->tab_points[0], test->tab_points[1], test->tab_points[2]);	
	
	point_free(points1);
	point_free(points2);
	point_free(points3);

	triangle_free(triangle);


	return 0 ;
}
