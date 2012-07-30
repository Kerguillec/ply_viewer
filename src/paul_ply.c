/*
paul_ply.c is wrapping the ply parser. 
Paul Kerguillec Jully 2012. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"


int ply_load (char* var_env) {

	PlyFile* file ;

	int i,j ;
	
	int nelems ;
	char** elem_names ;
	
	int file_type ;
	char filetypename[100] ;

	float version ;

	double* X ;
	double* Y ;
	double* Z ;
	int nb_points ;

	if(var_env == NULL)
		fprintf(stderr,"Error: Precise the file to examine");
	else{
	file = ply_open_for_reading( var_env, &nelems, &elem_names, &file_type, &version ) ;
	

	switch (file_type) {

		case PLY_ASCII:
			sprintf(filetypename,"ASCII" ) ;
			break ;
		case PLY_BINARY_BE:
			sprintf(filetypename,"BINARY LITTLE ENDIAN") ;
			break ;
		case PLY_BINARY_LE:
			sprintf(filetypename,"BINARY BIG ENDIAN" ) ;
			break ;
		default :
			fprintf(stderr,"This file type is unknown.\n") ;
			return -1 ;
	}
	
	
	printf("file type : %s \n", filetypename ) ;
	printf("version : %f\n", version ) ;
	printf("read %d elements : \n", nelems ) ;
	


	for ( i=0; i<nelems; i++ ) {
		printf("Element -> %s \n", elem_names[i] ) ;

		PlyProperty** prop ;
		int nb ;
		int nprops ;

		prop = ply_get_element_description( file, elem_names[i], &nb, &nprops ) ;
		
		printf("        -> %d occurences \n", nb ) ;
		printf("        -> %d properties \n", nprops ) ;
		
		if ( strcmp( elem_names[i], "vertex" ) == 0 ) {

			nb_points = nb ;
			X = (double*) malloc ( nb*sizeof(double) ) ;
			Y = (double*) malloc ( nb*sizeof(double) ) ;
			Z = (double*) malloc ( nb*sizeof(double) ) ;


		}
		
		for (j=0; j<nprops; j++ ) {
		
			printf("		Name: %s \n", prop[j]->name ) ;
	
			if ( strcmp( elem_names[i], "vertex" ) == 0 ) {


				if ( strcmp( prop[j]->name,"x" ) == 0 ) {
					printf("x\n") ;
					prop[j]->internal_type = PLY_DOUBLE ;	
					ply_get_element_setup(file,elem_names[i], 1, prop[j] ) ;
			                ply_get_element(file, X ) ;
				}

	/*			if ( strcmp( prop[j]->name,"y" ) == 0 ) {
					prop[j]->internal_type = PLY_DOUBLE ;	
					ply_get_element_setup(file,elem_names[i], 1, prop[j] ) ;
			                ply_get_element(file, Y ) ;
				}


				if ( strcmp( prop[j]->name,"z" ) == 0 ) {
					prop[j]->internal_type = PLY_DOUBLE ;	
					ply_get_element_setup(file,elem_names[i], 1, prop[j] ) ;
			                ply_get_element(file, Z ) ;
				}
*/
			}
	
		}

	}
}

//	for (i=0; i<nb_points; i++) 
//		printf("%lf %lf %lf \n", X[i], Y[i], Z[i] ) ;


	free(X) ;
	free(Y) ;
	free(Z) ;

	return 0;
}
