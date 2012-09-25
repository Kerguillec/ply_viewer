#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

/*******************************************************
Entry :
- Structure of a point 

Exit : 
- Structure which gives all points to form a triangle
*******************************************************/
Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3){

	Ttriangle* tmp;
	tmp = (Ttriangle*) malloc(sizeof( Ttriangle ) ) ;

	tmp->p1=point1;
	tmp->p2=point2;
	tmp->p3=point3;

	return tmp;
}


/*************************
This part show you the data 
Exit:
- Permit you to show point's structure 
*************************/
void debug_Tcoordinates(Ttriangle* A){ 
	int i;
       	fprintf(stderr,"Triangle's coordinates:\n");
	
       		fprintf(stderr,"	x[i] = %lf\n	y[i] = %lf\n	z[i] = %lf\n\n",A->p1->x,A->p1->y,A->p1->z);
       		fprintf(stderr,"	x[j] = %lf\n	y[j] = %lf\n	z[j] = %lf\n\n",A->p2->x,A->p2->y,A->p2->z);
       		fprintf(stderr,"	x[k] = %lf\n	y[k] = %lf\n	z[k] = %lf\n\n",A->p3->x,A->p3->y,A->p3->z);
	}

/****************************************
Free the triangle_free memory allocation.  
*****************************************/
void triangle_free(Ttriangle* triangle){
	free(triangle);
}
