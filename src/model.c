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

Tmodel* model_malloc(int nb_points, int nb_triangles){
	Tmodel* tmp;

	tmp = (Tmodel*) malloc(sizeof (Tmodel) );
/*	tmp->nb_p=nb_points;
	tmp->
	tmp->nb_t=nb_triangles;
*/	
	return tmp;
}






