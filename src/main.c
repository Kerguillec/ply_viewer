#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"
#include "model.h"
int main ( int argc, char** argv, char** envv ) {
 
	ply_load(argv[1]);
/*      Tpoint* points1;
	Tpoint* points2;
	Tpoint* points3;
	
	points1 = point_malloc(1,1,1);
	point_print(points1, stderr);	
	
	points2 = point_malloc(2,2,2);
	point_print(points2, stderr);	

	points3 = point_malloc(5,3,2);
	point_print(points3, stderr);	
	
	points3 = point_mallocRGB(5,3,2,64,246,247);
	point_print(points3, stderr);	

	Ttriangle* triangle;
	Ttriangle* triangle1;
	
	triangle = triangle_malloc(points1, points2, points3);
	triangle_print(triangle,stderr);
	
	// With coloration: 
	triangle1 = triangle_mallocRGB(points1, points2, points3, 54, 23, 245);
	triangle_print(triangle1,stderr);
*/
/*	
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
		
	// Set the matrix position of Tmodel* test	
	Tmatrix* matrix;
	matrix=matrix_malloc(5.0,4.0,3.0,2.0,
						1.0,5.0,3.0,2.0,
						4.0,5.0,6.0,7.0,
						8.0,9.0,2.0,1.0) ;
						
	model_set_posmat(test,matrix);	
		
		
*/		
/*	
	point_free(points1);
	point_free(points2);
	point_free(points3);

	triangle_free(triangle);
*/

	return 0 ;
}
