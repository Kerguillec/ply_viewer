#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"


typedef struct {

	Tpoint* p1 ;
	Tpoint* p2 ;
	Tpoint* p3 ;


} Ttriangle ;

Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3);
void debug_Tcoordinates(double X, double Y, double Z);
void triangle_free(Ttriangle*);

#endif

