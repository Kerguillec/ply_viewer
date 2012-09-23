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
void debug_Tcoordinates(Ttriangle* X, Ttriangle* Y, Ttriangle* Z){ 
	int i;
       	fprintf(stderr,"Triangle's coordinates:\n");
	
       		fprintf(stderr,"	x[1] = %lf\n	y[1] = %lf\n	z[1] = %lf\n\n",X->p1->x,Y->p1->y,Z->p1->z);
       		fprintf(stderr,"	x[2] = %lf\n	y[2] = %lf\n	z[2] = %lf\n\n",X->p2->x,Y->p2->y,Z->p2->z);
       		fprintf(stderr,"	x[3] = %lf\n	y[3] = %lf\n	z[3] = %lf\n\n",X->p3->x,Y->p3->y,Z->p3->z);
	}

/****************************************
Free the triangle_free memory allocation.  
*****************************************/
void triangle_free(Ttriangle* triangle){
	free(triangle);
}
