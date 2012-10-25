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

void model_add_point(Tmodel** add_point, int point){
	Tpoint* point1;
	point1 = point_malloc(9,8,7);
	add_point[0] = point1;
	fprintf(stderr," PointAdded= %i \n ",add_point[0]->point1->x);
}





void model_add_triangle(Tmodel* add_triangle, int triangle){




}

