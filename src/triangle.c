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
void debug_Tcoordinates(double X, double Y, double Z){ 

        printf("Triangle's coordinates:\nx = %lf\ny = %lf\nz = %lf\n",X,Y,Z);
}


/****************************************
Free the triangle_free memory allocation.  
*****************************************/
void triangle_free(Ttriangle* triangle){
	free(triangle);
}
