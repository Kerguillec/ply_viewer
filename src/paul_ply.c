/*
paul_ply.c is wrapping the ply parser. 
Paul Kerguillec Jully 2012. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"

/*
void *allocmem(size_type)
{
int* tmp;

	if(size_type == 0) 
	 	fprintf(stderr,"Invalid type file");

	if(size_type == 1 ) 
		tmp = malloc( sizeof (int));

	if(size_type == 2) 
		tmp = malloc(2 * sizeof (int));

	if(size_type == 3) 
		tmp = malloc( 4* sizeof (int));

	if(size_type ==  4) 
		tmp = malloc( sizeof (int));
	
	if(size_type == 5) 
		tmp = malloc(2 * sizeof (int));

	if(size_type == 6) 
		tmp = malloc(4 * sizeof (int));

	if(size_type == 7) 
		tmp = malloc(4 * sizeof (int));

	if(size_type == 8) 
		tmp = malloc(8 * sizeof (int));
}
*/

void ply_load (char* var_env) {

	PlyFile* file ;

	int i,j ;
	
	int nelems ;
	char** elem_names ;
	
	int file_type ;
	char filetypename[100] ;

	float version ;

	if(var_env == NULL)
		fprintf(stderr,"Error: Precise the file to examine");

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
		
		printf("        -> %d occurences \n", nb ) ;
		printf("        -> %d properties \n", nprops ) ;
		
		for (j=0; j<nprops; j++ ) {
		
		int* type_word;

			printf("%s \n", prop[j]->name ) ;
			printf("%i \n", prop[j]->external_type ) ;
			//type_word = prop[j]->external_type;
			//allocmem(type_word);
					
			//ply_get_element(file, allocmem );
		}

		
//	ply_get_element_setup( file, elem_names[0], 1, *prop ) ;
//	ply_get_element(file, filetypename);

	}

}
