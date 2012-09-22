#include <stdio.h>
#include <stdlib.h>
#include "point.h"

/**************************
Entry : 
- Point's coordinate  from ply file

Exit :
- Point's structure
***************************/
Tpoint* point_malloc(double x, double y, double z){

	Tpoint* tmp;
	tmp = (Tpoint*) malloc (sizeof(Tpoint));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return tmp;
}
/*************************
This part show you the data 
Exit:
- Permit you to show point's structure 
*************************/
void debug_Pcoordinates(double X, double Y, double Z){

	printf("Points coordinates:\nx = %lf\ny = %lf\nz = %lf\n",X,Y,Z);
}


/****************************************
Free the points memory allocation.  
*****************************************/

void point_free(Tpoint* point){
	free(point);
}
