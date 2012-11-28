#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"


typedef struct {

	Tpoint* p1 ;
	Tpoint* p2 ;
	Tpoint* p3 ;

	// int is_colored ;     ce triangle a-t-il une couleur specifique ? si 0 -> voir couleur des points, sinon, aplliquer couleur ci-dessous
	//
	// unsigned char R ;
	// unsigned char G ;
	// unsigned char B ;


} Ttriangle ;

Ttriangle* triangle_malloc(Tpoint* point1, Tpoint* point2, Tpoint* point3);  // FIXME  par default, is_colored = 0, R,G,B initialises a 255,255,255 
// FIXME Ttriangle* triangle_mallocRGB ( Tpoint*, Tpoint* Tpoint* unsigned char, unsigned char unsigned_char )  is_colored = 1

void debug_Tcoordinates(Ttriangle* A);		// FIXME renommer en void triangle_print ( Ttriangle*, FILE* stream )

void triangle_free(Ttriangle*);

#endif

