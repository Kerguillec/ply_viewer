#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"


typedef struct {

	Tpoint* tab_points[100];
	int nb_points;
	
	Ttriangle* tab_triangle[100];
	int nb_triangles ;

} Tmodel ;

Tmodel* model_malloc();

void model_add_point(Tmodel* model,double X, double Y, double Z);

void model_add_triangle(Tmodel* model, int triangle, Tpoint* p1, Tpoint* p2, Tpoint* p3);

//void model_free(Tmodel);


#endif
