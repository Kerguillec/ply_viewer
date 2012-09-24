#ifndef MODEL_H
#define MODEL_H

typedef struct {

	double xi;
	double yi;
	double zi;

	double xj;
	double yj;
	double zj;
	
	double xk;
	double yk;
	double zk;
} Tmatrix * ;

Tmatrix* matrix_malloc(double xi, double yi, double zi, double xj, double yj, double zj    , double xk, double yk, double zk);

Tmatrix* matrix_identity();

void matrix_free(Tmatrix* matrix);
#endif
