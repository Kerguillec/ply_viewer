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

	tmp->is_colored = 0;
	tmp->R = 255;
	tmp->G = 255;
	tmp->B = 255;
	
	return tmp;
}
Ttriangle* triangle_mallocRGB(Tpoint* point1, Tpoint* point2, Tpoint* point3, unsigned char R, unsigned char G, unsigned char B ){

	Ttriangle* tmp;
	tmp = (Ttriangle*) malloc(sizeof( Ttriangle ) ) ;

	tmp->p1=point1;
	tmp->p2=point2;
	tmp->p3=point3;

	tmp->is_colored = 1;
	tmp->R = R;
	tmp->G = G;
	tmp->B = B;
	
	return tmp;
}

/*************************
This part show you the data 
Exit:
- Permit you to show point's structure 
*************************/
void triangle_print(Ttriangle* A, FILE* stream){ 
	int i;
       	fprintf(stream,"Triangle's coordinates:\n");
	
       		fprintf(stream,"	x[i] = %lf\n	y[i] = %lf\n	z[i] = %lf\n\n",A->p1->x,A->p1->y,A->p1->z);
       		fprintf(stream,"	x[j] = %lf\n	y[j] = %lf\n	z[j] = %lf\n\n",A->p2->x,A->p2->y,A->p2->z);
       		fprintf(stream,"	x[k] = %lf\n	y[k] = %lf\n	z[k] = %lf\n\n",A->p3->x,A->p3->y,A->p3->z);
		fprintf(stream,"Triangle colorisation ===>   R = %hhu    G = %hhu    B = %hhu\n\n\n",A->R,A->G,A->B);
	}

/****************************************
Free the triangle_free memory allocation.  
*****************************************/
void triangle_free(Ttriangle* triangle){
	free(triangle);
}
