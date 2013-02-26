#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"


typedef struct {
	
	int  nb_points ;
	int* points ;
	int  is_colored ;  // if 0, the color of the points are used.
	                  // if 1, use the color underneath
	
	unsigned char R ;
	unsigned char G ;
	unsigned char B ;


} Ttriangle ;

Ttriangle* triangle_malloc( int p1, int p2, int p3);   
Ttriangle* triangle_mallocRGB( int p1, int p2, int p3, unsigned char R, unsigned char G, unsigned char B);

void triangle_print(Ttriangle* A, FILE* stream);

//FIXME normal_calcul  		
double Normal_Calcul(Trigidobject* A, Trigidobject* B);

void triangle_free(Ttriangle*);

#endif

