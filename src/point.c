#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "matrix.h"

/**************************
Entry : 
- Point's coordinate  from ply file

Exit :
- Point's structure
***************************/
	
/*********************************************
Tpoint* point_malloc without choice of RGB
**********************************************/
Tpoint* point_malloc(double x, double y, double z){

	Tpoint* tmp;
	tmp = (Tpoint*) malloc (sizeof(Tpoint));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;	

	// The color of the point is white .. 
	tmp->R = 255;
	tmp->G = 255;
	tmp->B = 255;

	return tmp;
}


/**********************************************
Tpoint_mallocRGB with the choice of RGB (unsigned char type)
***********************************************/
Tpoint* point_mallocRGB(double x, double y, double z, unsigned char R, unsigned char G, unsigned char B){

	Tpoint* tmp;
	tmp = (Tpoint*) malloc (sizeof(Tpoint));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;	

	//Colorisation RGB enable.
	tmp->R = R;
	tmp->G = G;
	tmp->B = B;

	return tmp;
}


/*****************************************************
Apply Matrice TODO
Work in 3*3 ?
******************************************************/
void point_applymat (Tpoint* point, Tmatrix* matrix ){

        point->x=(point->x)*(matrix->xi);
        point->y=(point->y)*(matrix->yi);
        point->z=(point->z)*(matrix->zi);
}


/*************************
This part show you the data 
Exit:
- Permit you to show point's structure 
*************************/
void point_print(Tpoint* point, FILE* stream){

	fprintf(stream,"Points coordinates:\n    x = %lf\n    y = %lf\n    z = %lf\n",point->x,point->y,point->z);
	fprintf(stream,"Points colorisation ===>  R = %hhu   G = %hhu    B = %hhu\n\n\n",point->R,point->G,point->B);
}


/****************************************
Free the points memory allocation.  
*****************************************/

void point_free(Tpoint* point){
	free(point);
}
