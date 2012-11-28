#ifndef MATRIX_H
#define MATRIX_H

typedef struct {

	// version seb :
	//
	//  int  lines ;
	//  int  cols ;
	//
	//  double* matrix ;
	//
	//  avec A(i,j) = matrix[ i*cols + j ] ;
	//
	//
	//  autre possibilite :
	//
	//  nommer TransfMatri donc forcement 4,4
	//
	//  double matrix[16] ;



	double wi;
	double xi;
	double yi;
	double zi;

	double wj;
	double xj;
	double yj;
	double zj;
	
	double wk;
	double xk;
	double yk;
	double zk;

	double wl;
	double xl;
	double yl;
	double zl;

} Tmatrix ;

Tmatrix* matrix_malloc( double wi, double xi, double yi, double zi, 
		        double wj, double xj, double yj, double zj, 
			double wk, double xk, double yk, double zk,
			double wl, double xl, double yl, double zl  );

Tmatrix* matrix_identity();

void matrix_free(Tmatrix* matrix);



// FIXME
//
//  double matrix_get( Tmatrix*, int i, int j ) ;
//  void   matrix_set( Tmatrix*, int i, int j, double value ) ;
//
//
//
//



#endif
