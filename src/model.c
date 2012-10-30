#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "point.h"

/********************************
Currently in development. That why for the moment you couldn't work with matrices.  

Entry :
- Model.c is wrapping all the structures of Point, Triangle and Matrix

Exit :
- Will give the entire modelisation of your object. 
********************************/

Tmodel* model_malloc(){
	Tmodel* tmp;
	tmp = (Tmodel*) malloc(sizeof (Tmodel) );
	return tmp;
}

void model_add_point(Tmodel* addr_point, int i, double X, double Y, double Z){
	Tpoint* point;
	point = point_malloc(X,Y,Z);

	addr_point->tab_points = &point;
	addr_point->nb_points = i;

	fprintf(stderr," Nombre de points %i \n ", addr_point->nb_points);
}





void model_add_triangle(Tmodel* add_triangle, int triangle){




}

