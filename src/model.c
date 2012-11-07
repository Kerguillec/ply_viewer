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

void model_add_point(Tmodel* addr_point, double X, double Y, double Z){
	Tpoint* point = point_malloc(X,Y,Z);

	//Save the location of the pointer "point" into the table "tab_points" 
	addr_point->tab_points[addr_point->nb_points] = point;
	addr_point->nb_points++;

	fprintf(stderr,"----->DEBUG How many points: %i \n", addr_point->nb_points);
	fprintf(stderr,"----->DEBUG @ of point in tab_point %x \n", addr_point->tab_points[0]);
	// Print the field of the structure Tpoint	
	fprintf(stderr,"----->DEBUG Point: %lf \n", addr_point->tab_points[0]->x);
}





void model_add_triangle(Tmodel* add_triangle, int triangle){




}

