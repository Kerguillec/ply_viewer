#ifndef POINT_H
#define POINT_H


typedef struct {

	double x ;
	double y ;
	double z ;


} Tpoint ;

Tpoint* point_malloc( double x, double y, double z );	
void point_free(Tpoint*);

void debug_Pcoordinates(double X, double Y, double Z);





#endif

