#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "triangle.h"


typedef struct {

	Tpoint** tab_points;
	int nb_points;
	
	Ttriangle** tab_triangle;
	int nb_triangles ;

} Tmodel ;

Tmodel* model_malloc(int nb_points, int nb_triangles);

void model_free(Tmodel*);




#endif
