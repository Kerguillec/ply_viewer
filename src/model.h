#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"


typedef struct {

	Tpoint** tab_points[100];
	int nb_points;
	
	Ttriangle** tab_triangle;
	int nb_triangles ;

} Tmodel ;

Tmodel* model_malloc();

void model_add_point(Tmodel* addr_point,double X, double Y, double Z);

void model_add_triangle(Tmodel* add_triangle, int triangle);

// void model_free(Tmodel*);


#endif
