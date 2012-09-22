#ifndef POINT_H
#define POINT_H


typedef struct {

	double x ;
	double y ;
	double z ;


} Tpoint ;

Tpoint* point_malloc( double x, double y, double z );	

void debug_Pcoordinates(double X, double Y, double Z);

void point_free(Tpoint*);



#endif

