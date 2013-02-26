#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"
#include "matrix.h"

#define MODEL_SIZE 10000 

typedef struct Srigidobject {

	Tpoint* tab_points;
	int nb_points;
	int max_points ;
	
	Ttriangle* tab_triangles;
	int nb_triangles ;
	int max_triangles ;

	Tmatrix* pos ;			// Position matrix

} Trigidobject ;

Trigidobject* rigidobject_malloc();

void rigidobject_add_point(Trigidobject* rigidobject, double X, double Y, double Z);
void rigidobject_add_triangle(Trigidobject* rigidobject, Tpoint* p1, Tpoint* p2, Tpoint* p3);
void rigidobject_set_posmat(Trigidobject* rigidobject, Tmatrix* matrix);
void rigidobject_mult_posmat(Trigidobject* rigidobject, Tmatrix* matrix);
Tpoint* Normal_Calcul(double X, double Y, double Z,
							double Xb, double Yb, double Zb);
void rigidobject_print(Trigidobject*);
void rigidobject_free(Trigidobject*);


#endif
