#include <stdio.h>
#include <stdlib.h>

#include "triangle.h"


Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3){

	Ttriangle* tmp;
	tmp = malloc(sizeof( Ttriangle ));
	
	tmp->p1=point1;


	return tmp;
}

void triangle_free(Ttriangle*){

	free(Ttriangle*);

}
