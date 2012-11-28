#ifndef POINT_H
#define POINT_H


typedef struct {

	double x ;
	double y ;
	double z ;

	// unsigned char R ;          information de couleur
	// unsigned char G ;
	// unsigned char B ;

	



} Tpoint ;

Tpoint* point_malloc( double x, double y, double z );	// FIXME dans celui ci, la couleur est automatiquement mise a blanc ( 255 sur chaque composante )
// FIXME Tpoint* point_mallocRGB ( double x, double y, double z, unsigned char R, unsigned char G, unsigned char B )

void point_free(Tpoint*);

void debug_Pcoordinates(double X, double Y, double Z);		// FIXME transformer en void point_print ( Tpoint* ) ;

void point_applymat ( Tpoint*, Tmatrix* ) ;			// FIXME a coder ... applique la matrice au point P




#endif

