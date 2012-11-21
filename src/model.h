#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"
#include "matrix.h"

#define MODEL_SIZE 1000 

typedef struct Smodel {

	Tpoint** tab_points;
	int nb_points;
	
	Ttriangle** tab_triangles;
	int nb_triangles ;

	Tmatrix* pos ;			// Position matrix

	struct Smodel* next ;		// pointer to the next model structure

} Tmodel ;

Tmodel* model_malloc();

void model_add_point(Tmodel* model, double X, double Y, double Z);
void model_add_triangle(Tmodel* model, Tpoint* p1, Tpoint* p2, Tpoint* p3);
void model_set_posmat(Tmodel* model, Tmatrix* matrix);
void model_mult_posmat(Tmodel* model, Tmatrix* matrix);
void model_free(Tmodel);


#endif
