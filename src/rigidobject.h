#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"
#include "matrix.h"

#define MODEL_SIZE 1000 

typedef struct Srigidobject {

	Tpoint* tab_points;
	int nb_points;
	
	Ttriangle* tab_triangles;
	int nb_triangles ;

	Tmatrix* pos ;			// Position matrix

	struct Srigidobject* next ;		// pointer to the next model structure

} Trigidobject ;

Trigidobject* rigidobject_malloc();

void rigidobject_add_point(Trigidobject* rigidobject, double X, double Y, double Z);
void rigidobject_add_triangle(Trigidobject* rigidobject, Tpoint* p1, Tpoint* p2, Tpoint* p3);
void rigidobject_set_posmat(Trigidobject* rigidobject, Tmatrix* matrix);
void rigidobject_mult_posmat(Trigidobject* rigidobject, Tmatrix* matrix);
void rigidobject_print(Trigidobject*);
void rigidobject_free(Trigidobject*);


#endif
