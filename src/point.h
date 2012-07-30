#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {

double x ;
double y ;
double z ;


} Tpoint ;

Tpoint* point_malloc( double x, double y, double z );	

void point_free(Tpoint*);
#endif

