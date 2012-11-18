#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "point.h"

/********************************
Currently in development. That why for the moment you couldn't work with matrices.  

Entry :
- Model.c is wrapping all structures of a Point, Triangle and Matrix(later).

Exit :
- Will give the entire modelisation of your object. 
********************************/

Tmodel* model_malloc(){
	Tmodel* tmp;
	tmp = (Tmodel*) malloc(sizeof (Tmodel) );
	return tmp;
}

void model_add_point(Tmodel* model, double X, double Y, double Z){

        int Length;
	// Verify if it's the first use of the points table.
        if(model->nb_points == 0){ // If this condition is true that means we have to initialise the length and allocate the memory. 
                Length = 100;
                model->tab_points = malloc((Length)*sizeof(Tpoint*));
        }           
	
	// It verify if the length of the table is enough, if isn't the case that means we have to realloc. 
        if(model->nb_points >= Length){
                Length *= 1000; 
                model->tab_points = realloc(model->tab_points, (Length)*sizeof(Tpoint*));
        }

	Tpoint* point = point_malloc(X,Y,Z);

	//Save the location of the pointer "point" into the table "tab_points" 
	model->tab_points[model->nb_points] = point;
	model->nb_points++;

	fprintf(stderr,"----->DEBUG Which point: %i \n", model->nb_points);
	fprintf(stderr,"----->DEBUG @ of point in tab_point %x \n", model->tab_points[model->nb_points-1]);
	// Print the field of the structure Tpoint	
	fprintf(stderr,"----->DEBUG Point X: %lf \n", model->tab_points[model->nb_points-1]->x);
	fprintf(stderr,"----->DEBUG Point Y: %lf \n", model->tab_points[model->nb_points-1]->y);
	fprintf(stderr,"----->DEBUG Point Z: %lf \n\n", model->tab_points[model->nb_points-1]->z);
}





void model_add_triangle(Tmodel* model, int triangle, Tpoint* p1, Tpoint* p2, Tpoint* p3){

        int Length; // Length for table. It's initialised in the next condition. 

    	// It verify if it's the first use of the triangles table.
        if(model->nb_triangles == 0){ // If this condition is true that means we have to initialise the length and allocate the mem.
                Length = 100;
                model->tab_triangle = malloc((Length)*sizeof(Tpoint*));
        }    
	
	// It verify if the length of the table is enough, if isn't the case that means we have to realloc.
        if(model->nb_triangles >= Length){
                Length *= 1000; 
                model->tab_triangle = realloc(model->tab_triangle, (Length)*sizeof(Ttriangle*));
        }  

	Ttriangle* Atriangle = triangle_malloc(p1,p2,p3);

	//Save the location of the pointer "triangle" into the table "tab_triangle" 
	model->tab_triangle[model->nb_triangles] = Atriangle;
	model->nb_triangles++;

	fprintf(stderr,"----->DEBUG How many triangless: %i \n", model->nb_triangles);
	fprintf(stderr,"----->DEBUG @ of triangle in tab_triangle %x \n", model->tab_triangle[0]);
	// Print the field of the structure Ttriangle	
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p1->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p1->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangle[model->nb_triangles-1]->p1->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p2->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p2->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangle[model->nb_triangles-1]->p2->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p3->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangle[model->nb_triangles-1]->p3->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangle[model->nb_triangles-1]->p3->z);

}

