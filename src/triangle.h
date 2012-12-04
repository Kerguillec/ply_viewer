#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"


typedef struct {
	
	int a;
	Tpoint* p1 ;
	Tpoint* p2 ;
	Tpoint* p3 ;
	
	int is_colored ;  // if 0, the color of the points are used.
	                  // if 1, use the color underneath
	
	unsigned char R ;
	unsigned char G ;
	unsigned char B ;


} Ttriangle ;

Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3);   
Ttriangle* triangle_mallocRGB(Tpoint* point1, Tpoint* point2, Tpoint* point3, unsigned char R, unsigned char G, unsigned char B);

void triangle_print(Ttriangle* A, FILE* stream);		

void triangle_free(Ttriangle*);

#endif

