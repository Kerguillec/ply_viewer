#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*******************************************************************
matrix_malloc save a matrix.
Will should be used to do transformation or translation operations

Entry: 3x3 matrix.

Exit: your 3x3 matrix. 

********************************************************************/

Tmatrix* matrix_malloc( double wi, double xi, double yi, double zi, 
			double wj, double xj, double yj, double zj, 
			double wk, double xk, double yk, double zk,
			double wl, double xl, double yl, double zl ) { 
			
	Tmatrix* tmp;
	tmp = (Tmatrix*) malloc(sizeof (Tmatrix) );
	
        tmp->wi=wi;
        tmp->xi=xi;
        tmp->yi=yi;
        tmp->zi=zi;
	tmp->wj=wj;
        tmp->xj=xj;
        tmp->yj=yj;
        tmp->zj=zj;
	tmp->wk=wk;
        tmp->xk=xk;
        tmp->yk=yk;
        tmp->zk=zk;
	tmp->wl=wl;
        tmp->xl=xl;
        tmp->yl=yl;
        tmp->zl=zl;

	return tmp;
}

/*********************************************************************
A matrix identity:
|1 0 0|
|0 1 0|
|0 0 1|  

Entry: nothing ...
Exit: give you a matrix identity
*********************************************************************/
Tmatrix* matrix_identity(){

	return matrix_malloc ( 1.0, 0.0, 0.0, 0.0, 
	                       0.0, 1.0, 0.0, 0.0,
			       0.0, 0.0, 1.0, 0.0,
			       0.0, 0.0, 0.0, 1.0 ) ;

}

/***********************************************************************
Keep It Simple, and Stupid ? (KISS philosophy =) )
Free the matrix_malloc ... 
***********************************************************************/
void matrix_free(Tmatrix* matrix){
	free(matrix);
}
