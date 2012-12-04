#include <stdio.h>
#include <stdlib.h>

#include "model.h"

#define DEBUG 1

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

	tmp->tab_points = (Tpoint**) malloc ( MODEL_SIZE * sizeof ( Tpoint* ) ) ;
	// TODO tester si le malloc renvoie NULL a chaque malloc
	
	tmp->nb_points = 0 ;

	tmp->tab_triangles = ( Ttriangle** ) malloc ( MODEL_SIZE * sizeof ( Ttriangle* ) ) ;
	tmp->nb_triangles = 0 ;

	tmp->pos = matrix_malloc ( 1.0, 0.0, 0.0, 0.0,  
	                           0.0, 1.0, 0.0, 0.0, 
				   0.0, 0.0, 1.0, 0.0,
				   0.0, 0.0, 0.0, 1.0 ) ; 

	tmp->next = NULL ;

	return tmp;
}

void model_add_point(Tmodel* model, double X, double Y, double Z){

	// It verify if the length of the table is enough, if isn't the case that means we have to realloc. 
        
	if( model->nb_points == MODEL_SIZE ) {
                
		if ( model->next == NULL )
			model->next = model_malloc() ;

		model_add_point ( model->next, X, Y, Z ) ;
        
	} else {

		Tpoint* point = point_malloc(X,Y,Z);
		
		//Save the location of the pointer "point" into the table "tab_points" 
		
		model->tab_points[model->nb_points] = point;
		model->nb_points++;

#if ( DEBUG )

		fprintf(stderr,"----->DEBUG Which point: %i \n", model->nb_points);
		fprintf(stderr,"----->DEBUG @ of point in tab_point %x \n", (unsigned int) model->tab_points[model->nb_points-1]);
		// Print the field of the structure Tpoint	
		fprintf(stderr,"----->DEBUG Point X: %lf \n", model->tab_points[model->nb_points-1]->x);
		fprintf(stderr,"----->DEBUG Point Y: %lf \n", model->tab_points[model->nb_points-1]->y);
		fprintf(stderr,"----->DEBUG Point Z: %lf \n\n", model->tab_points[model->nb_points-1]->z);

#endif


	}
}





void model_add_triangle(Tmodel* model, Tpoint* p1, Tpoint* p2, Tpoint* p3){

	// It verify if the length of the table is enough, if isn't the case that means we have to realloc. 
        
	if( model->nb_triangles == MODEL_SIZE ) {
                
		if ( model->next == NULL )
			model->next = model_malloc() ;

		model_add_triangle ( model->next, p1, p2, p3 ) ;
        
	} else {

		Ttriangle* triangle = triangle_malloc(p1,p2,p3);
		
		//Save the location of the pointer "point" into the table "tab_points" 
		
		model->tab_triangles[model->nb_triangles] = triangle;
		model->nb_triangles++;

#if ( DEBUG )


	fprintf(stderr,"----->DEBUG How many triangless: %i \n", model->nb_triangles);
	fprintf(stderr,"----->DEBUG @ of triangle in tab_triangle %x \n", (unsigned int) model->tab_triangles[0]); //FIXME Wpointer to int cast warning ?
	// Print the field of the structure Ttriangle	
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p1->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p1->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangles[model->nb_triangles-1]->p1->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p2->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p2->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangles[model->nb_triangles-1]->p2->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p3->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", model->tab_triangles[model->nb_triangles-1]->p3->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", model->tab_triangles[model->nb_triangles-1]->p3->z);
#endif
	}
}

void model_set_posmat(Tmodel* model, Tmatrix* matrix) {

// Define the matrix position for our model

	model->pos->wi=matrix->wi;
        model->pos->xi=matrix->xi;
        model->pos->yi=matrix->yi;
        model->pos->zi=matrix->zi;
	   
	model->pos->wj=matrix->wj;
        model->pos->xj=matrix->xj;
        model->pos->yj=matrix->yj;
        model->pos->zj=matrix->zj;
		
		
	model->pos->wk=matrix->wk;
        model->pos->xk=matrix->xk;
        model->pos->yk=matrix->yk;
        model->pos->zk=matrix->zk;
		
		
	model->pos->wl=matrix->wl;
        model->pos->xl=matrix->xl;
        model->pos->yl=matrix->yl;
        model->pos->zl=matrix->zl;
		
#if ( DEBUG )

fprintf(stderr," Debug Position Matrix : %lf ",model->pos->wi);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->xi);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->yi);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->zi);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->wj);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->xj);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->yj);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->zj);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->wk);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->xk);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->yk);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->zk);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->wl);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->xl);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->yl);
fprintf(stderr," Debug Position Matrix : %lf ",model->pos->zl);


#endif
}

void model_mult_posmat(Tmodel* model, Tmatrix* matrix) {

	model->pos->wi*=(matrix->wi);
        model->pos->xi=(model->pos->wi)*(matrix->xi);
        model->pos->yi=(model->pos->wi)*(matrix->yi);
        model->pos->zi=(model->pos->wi)*(matrix->zi);
	   
	model->pos->wj=(model->pos->wj)*(matrix->wj);
        model->pos->xj=(model->pos->wj)*(matrix->xj);
        model->pos->yj=(model->pos->wj)*(matrix->yj);
        model->pos->zj=(model->pos->wj)*(matrix->zj);
		
		
	model->pos->wk=(model->pos->wk)*(matrix->wk);
        model->pos->xk=(model->pos->wk)*(matrix->xk);
        model->pos->yk=(model->pos->wk)*(matrix->yk);
        model->pos->zk=(model->pos->wk)*(matrix->zk);
		
		
	model->pos->wl=(model->pos->wl)*(matrix->wl);
        model->pos->xl=(model->pos->wl)*(matrix->xl);
        model->pos->yl=(model->pos->wl)*(matrix->yl);
        model->pos->zl=(model->pos->wl)*(matrix->zl);

}

