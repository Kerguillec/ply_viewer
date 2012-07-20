#include <stdio.h>
#include <stdlib.h>
#include "ply.h"


int main ( int argc, char** argv, char** envv ) {

	PlyFile* file ;

	int i ;
	
	int nelems ;
	char** elem_names ;
	
	int file_type ;
	char filetypename[100] ;

	float version ;


	file = ply_open_for_reading( argv[1], &nelems, &elem_names, &file_type, &version ) ;


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
			fprintf(stderr,"this file type is unknown.\n") ;
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
		
		printf("        -> %d \n", nb ) ;
		printf("        -> %d properties \n", nprops ) ;


	}

	

 	return 0 ;

}
