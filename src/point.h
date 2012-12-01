#ifndef POINT_H
#define POINT_H

#include "matrix.h"

typedef struct {

	double x ;
	double y ;
	double z ;

	unsigned char R ;
	unsigned char G ;
	unsigned char B ;

} Tpoint ;

Tpoint* point_malloc( double x, double y, double z);	


Tpoint* point_mallocRGB( double x, double y, double z, unsigned char R, unsigned char G, unsigned char B);


void point_free(Tpoint*);

void point_print(Tpoint* point, FILE* stream);

void point_applymat (Tpoint* point, Tmatrix* matrix );			// FIXME a coder ... applique la matrice au point P




#endif

