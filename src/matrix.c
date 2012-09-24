#include "matrix.h"

/*******************************************************************
matrix_malloc save a matrix.
Will should be used to do transformation or translation operations

Entry: 3x3 matrix.

Exit: your 3x3 matrix. 

********************************************************************/

Tmatrix* matrix_malloc(double xi, double yi, double zi, double xj, double yj, double zj, double xk, double yk, double zk){
	Tmatrix* tmp;
	tmp = (Tmatrix *) malloc(sizeof (Tmatrix) );
	
        tmp->xi=xi;
        tmp->yi=yi;
        tmp->zi=zi;
        tmp->xj=xj;
        tmp->yj=yj;
        tmp->zj=zj;
        tmp->xk=xk;
        tmp->yk=yk;
        tmp->zk=zk;

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

	Tmatrix* tmp;
	tmp = (Tmatrix *) malloc(sizeof (Tmatrix) );
	
        tmp->xi=1;
        tmp->yi=0;
        tmp->zi=0;
        tmp->xj=0;
        tmp->yj=1;
        tmp->zj=0;
        tmp->xk=0;
        tmp->yk=0;
        tmp->zk=1;

return tmp;
}

/***********************************************************************
Keep It Simple, and Stupid ? (KISS philosophy =) )
Free the matrix_malloc ... 
***********************************************************************/

void matrix_free(Ttriangle* triangle){
free(matrix);
}




***********************************************************************/



