#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"
#include "model.h"
int main ( int argc, char** argv, char** envv ) {
 
	Trigidobject*	lapin ;

	printf(" File : %s \n", argv[1] ) ;

	lapin = rigidobject_malloc() ;

	rigidobject_loadply( lapin, argv[1] ) ;

	rigidobject_print ( lapin ) ;

	rigidobject_free ( lapin ) ;

	return 0 ;
}
