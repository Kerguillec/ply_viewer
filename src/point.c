#include <stdio.h>
#include <stdlib.h>

#include "point.h"

Tpoint* point_malloc(double x, double y, double z){

	Tpoint* tmp;
	tmp = (Tpoint*) malloc (sizeof(Tpoint));
	tmp->x;
	tmp->y;
	tmp->z;
	return tmp;
}

void point_free(Tpoint* point){
	free(point);
}
