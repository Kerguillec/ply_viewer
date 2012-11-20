#ifndef MATRIX_H
#define MATRIX_H

typedef struct {

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
#endif
