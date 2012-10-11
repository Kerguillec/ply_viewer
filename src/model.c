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

Tmodel* model_malloc(){
	Tmodel* tmp;
	tmp = (Tmodel*) malloc(sizeof (Tmodel) );
	return tmp;
}

void model_add_point(Tmodel*, int point){
Tmodel* add_point;
add_point=model_malloc();

add_point[0]=point;
fprintf(stderr," PointAdded= %i \n ",add_point[0]);

}





void model_add_triangle(Tmodel*, int triangle){




}

