#include <stdio.h>
#include <stdlib.h>

#include "rigidobject.h"

#define DEBUG 1

/********************************
Currently in development. That why for the moment you couldn't work with matrices.  

Entry :
- Model.c is wrapping all structures of a Point, Triangle and Matrix(later).

Exit :
- Will give the entire modelisation of your object. 
********************************/

Trigidobject* rigidobject_malloc(){
	Trigidobject* tmp;
	tmp = (Trigidobject*) malloc(sizeof (Trigidobject) );

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

void rigidobject_add_point(Trigidobject* rigidobject, double X, double Y, double Z){

	// It verify if the length of the table is enough, if isn't the case that means we have to realloc. 
        
	if( rigidobject->nb_points == MODEL_SIZE ) {
                
		if ( rigidobject->next == NULL )
			rigidobject->next = rigidobject_malloc() ;

		rigidobject_add_point ( rigidobject->next, X, Y, Z ) ;
        
	} else {

		Tpoint* point = point_malloc(X,Y,Z);
		
		//Save the location of the pointer "point" into the table "tab_points" 
		
		rigidobject->tab_points[rigidobject->nb_points] = point;
		rigidobject->nb_points++;

#if ( DEBUG )

		fprintf(stderr,"----->DEBUG Which point: %i \n", rigidobject->nb_points);
		fprintf(stderr,"----->DEBUG @ of point in tab_point %x \n", (unsigned int) rigidobject->tab_points[rigidobject->nb_points-1]);
		// Print the field of the structure Tpoint	
		fprintf(stderr,"----->DEBUG Point X: %lf \n", rigidobject->tab_points[rigidobject->nb_points-1]->x);
		fprintf(stderr,"----->DEBUG Point Y: %lf \n", rigidobject->tab_points[rigidobject->nb_points-1]->y);
		fprintf(stderr,"----->DEBUG Point Z: %lf \n\n", rigidobject->tab_points[rigidobject->nb_points-1]->z);

#endif


	}
}





void rigidobject_add_triangle(Trigidobject* rigidobject, Tpoint* p1, Tpoint* p2, Tpoint* p3){

	// It verify if the length of the table is enough, if isn't the case that means we have to realloc. 
        
	if( rigidobject->nb_triangles == MODEL_SIZE ) {
                
		if ( rigidobject->next == NULL )
			rigidobject->next = rigidobject_malloc() ;

		rigidobject_add_triangle ( rigidobject->next, p1, p2, p3 ) ;
        
	} else {

		Ttriangle* triangle = triangle_malloc(p1,p2,p3);
		
		//Save the location of the pointer "point" into the table "tab_points" 
		
		rigidobject->tab_triangles[rigidobject->nb_triangles] = triangle;
		rigidobject->nb_triangles++;

#if ( DEBUG )


	fprintf(stderr,"----->DEBUG How many triangless: %i \n", rigidobject->nb_triangles);
	fprintf(stderr,"----->DEBUG @ of triangle in tab_triangle %x \n", (unsigned int) rigidobject->tab_triangles[0]); //FIXME Wpointer to int cast warning ?
	// Print the field of the structure Ttriangle	
	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p1->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p1->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p1->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p2->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p2->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p2->z);

	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p3->x);
	fprintf(stderr,"----->DEBUG triange : %lf \n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p3->y);
	fprintf(stderr,"----->DEBUG triange : %lf \n\n", rigidobject->tab_triangles[rigidobject->nb_triangles-1]->p3->z);
#endif
	}
}

void rigidobject_set_posmat(Trigidobject* rigidobject, Tmatrix* matrix) {

// Define the matrix position for our rigidobject

	rigidobject->pos->wi=matrix->wi;
        rigidobject->pos->xi=matrix->xi;
        rigidobject->pos->yi=matrix->yi;
        rigidobject->pos->zi=matrix->zi;
	   
	rigidobject->pos->wj=matrix->wj;
        rigidobject->pos->xj=matrix->xj;
        rigidobject->pos->yj=matrix->yj;
        rigidobject->pos->zj=matrix->zj;
		
		
	rigidobject->pos->wk=matrix->wk;
        rigidobject->pos->xk=matrix->xk;
        rigidobject->pos->yk=matrix->yk;
        rigidobject->pos->zk=matrix->zk;
		
		
	rigidobject->pos->wl=matrix->wl;
        rigidobject->pos->xl=matrix->xl;
        rigidobject->pos->yl=matrix->yl;
        rigidobject->pos->zl=matrix->zl;
		
#if ( DEBUG )

fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->wi);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->xi);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->yi);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->zi);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->wj);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->xj);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->yj);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->zj);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->wk);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->xk);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->yk);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->zk);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->wl);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->xl);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->yl);
fprintf(stderr," Debug Position Matrix : %lf ",rigidobject->pos->zl);


#endif
}

void rigidobject_mult_posmat(Trigidobject* rigidobject, Tmatrix* matrix) {

	rigidobject->pos->wi*=(matrix->wi);
        rigidobject->pos->xi=(rigidobject->pos->wi)*(matrix->xi);
        rigidobject->pos->yi=(rigidobject->pos->wi)*(matrix->yi);
        rigidobject->pos->zi=(rigidobject->pos->wi)*(matrix->zi);
	   
	rigidobject->pos->wj=(rigidobject->pos->wj)*(matrix->wj);
        rigidobject->pos->xj=(rigidobject->pos->wj)*(matrix->xj);
        rigidobject->pos->yj=(rigidobject->pos->wj)*(matrix->yj);
        rigidobject->pos->zj=(rigidobject->pos->wj)*(matrix->zj);
		
		
	rigidobject->pos->wk=(rigidobject->pos->wk)*(matrix->wk);
        rigidobject->pos->xk=(rigidobject->pos->wk)*(matrix->xk);
        rigidobject->pos->yk=(rigidobject->pos->wk)*(matrix->yk);
        rigidobject->pos->zk=(rigidobject->pos->wk)*(matrix->zk);
		
		
	rigidobject->pos->wl=(rigidobject->pos->wl)*(matrix->wl);
        rigidobject->pos->xl=(rigidobject->pos->wl)*(matrix->xl);
        rigidobject->pos->yl=(rigidobject->pos->wl)*(matrix->yl);
        rigidobject->pos->zl=(rigidobject->pos->wl)*(matrix->zl);

}
void rigidobject_print(Trigidobject* object){
//TODO
}

void rigidobject_free(Trigidobject* object){
 free(object); //FIXME
}
