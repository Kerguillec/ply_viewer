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
	return tmp;
}

void model_setpoint(Tmodel*, int i, int x, int y, int z){



}

void model_settriangle(Tmodel*, int j, int p1, int p2, int p3){




}

