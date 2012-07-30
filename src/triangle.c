#include <stdio.h>
#include <stdlib.h>

#include "triangle.h"


Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3){

	Ttriangle* tmp;
	tmp = (Ttriangle*) malloc(sizeof( Ttriangle ) ) ;
	tmp->p1=point1;
	tmp->p2=point2;
	tmp->p3=point3;
	return tmp;
}

void triangle_free(Ttriangle* triangle){
	free(triangle);
}
