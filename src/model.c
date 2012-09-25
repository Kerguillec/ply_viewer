#include <stdio.h>
#include <stdlib.h>
#include "model.h"


/********************************
Currently in development. That why for the moment you couldn't work with matrices.  

Entry :
- Model.c is wrapping all the structures of Point, Triangle and Matrix

Exit :
- Will give the entire modelisation of your object. 
********************************/

Tmodel* model_malloc(Tpoint** tab_points, int nb_points, int nb_triangles, Ttriangle** tab_triangle){
	Tmodel* tmp;
	tmp = (Tmodel*) malloc(sizeof (Tmodel) );
/*
	tmp->tab_points=
	tmp->nb_p=nb_points;

	tmp->tab_triangles;
	tmp->nb_t=nb_triangles;
*/	
	return tmp;
}






