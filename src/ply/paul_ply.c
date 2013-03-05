/*
paul_ply.c is wrapping the ply parser. 
Paul Kerguillec Jully 2012. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"

int rigidobject_loadply (Trigidobject* object, char* filename) {

	PlyFile* file ;

	int i,j ;
	
	int nelems ;
	char** elem_names ;
	
	int file_type ;
	char filetypename[100] ;
	float version ;


	PlyProperty vertexProps[] = {
		{ "x", PLY_FLOAT, PLY_DOUBLE, offsetof( struct _Tpoint, x ), 0, 0, 0, 0 },
		{ "y", PLY_FLOAT, PLY_DOUBLE, offsetof( struct _Tpoint, y ), 0, 0, 0, 0 },
		{ "z", PLY_FLOAT, PLY_DOUBLE, offsetof( struct _Tpoint, z ), 0, 0, 0, 0 }
	} ;

	
	PlyProperty faceProps[] = {
		{ "vertex_indices", PLY_INT, PLY_INT, offsetof( Ttriangle, points ), 1, PLY_UCHAR, PLY_UCHAR, offsetof( Ttriangle, nb_points ) }
	};




	if(filename == NULL) {
		fprintf(stderr,"Error: Precise the file to examine");
		return -1 ;
	}


	file = ply_open_for_reading( filename, &nelems, &elem_names, &file_type, &version ) ;
	

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
		
		printf(" -> %d occurences \n", nb ) ;
		printf(" -> %d properties \n", nprops ) ;
		
		if ( strcmp( elem_names[i], "vertex" ) == 0 ) {
			object->nb_points = nb ;
			object->tab_points = malloc ( object->nb_points * sizeof ( Tpoint ) ) ;
			for (j=0; j<nprops; j++ ) {
				printf("    -> Name: %s \n", prop[j]->name ) ;
				if ( strcmp( prop[j]->name,"x" ) == 0 ) {
					ply_get_property( file, "vertex", &vertexProps[0] );

				}
				if ( strcmp( prop[j]->name,"y" ) == 0 ) {
					ply_get_property( file, "vertex", &vertexProps[1] );
				}
				if ( strcmp( prop[j]->name,"z" ) == 0 ) {
					ply_get_property( file, "vertex", &vertexProps[2] );
				}
			}

			for (j=0; j<object->nb_points; j++ )
				ply_get_element( file, &(object->tab_points[j]) ) ;
		}

		if ( strcmp( elem_names[i], "face" ) == 0 ) {
			object->nb_triangles = nb ;
			object->tab_triangles = malloc ( object->nb_triangles * sizeof ( Ttriangle ) ) ;
		
			for ( j=0; j<nprops; j++ ) {
				printf("    -> Name: %s \n", prop[j]->name);
				if ( strcmp( prop[j]->name,"vertex_indices")==0 ) 
					 ply_get_property( file, "face", &faceProps[0] );	
				
			}
	
			for (j=0; j<object->nb_triangles; j++ )
				ply_get_element( file, &(object->tab_triangles[j]) ) ;
		
		}	
	
/* TODO color provided by PLY !! 
		if ( strcmp( elem_names[i], "red" ) == 0 ) {
			object->nb_triangles = nb ;
			object->tab_triangles = malloc ( object->nb_triangles * sizeof ( Ttriangle ) ) ;
		
			for ( j=0; j<nprops; j++ ) {
				printf("    -> Name: %s \n", prop[j]->name);
				if ( strcmp( prop[j]->name,"vertex_indices")==0 ) 
					 ply_get_property( file, "face", &faceProps[0] );	
				
			}
	
			for (j=0; j<object->nb_triangles; j++ )
				ply_get_element( file, &(object->tab_triangles[j]) ) ;
		
		}
		if ( strcmp( elem_names[i], "green" ) == 0 ) {
			object->nb_triangles = nb ;
			object->tab_triangles = malloc ( object->nb_triangles * sizeof ( Ttriangle ) ) ;
		
			for ( j=0; j<nprops; j++ ) {
				printf("    -> Name: %s \n", prop[j]->name);
				if ( strcmp( prop[j]->name,"vertex_indices")==0 ) 
					 ply_get_property( file, "face", &faceProps[0] );	
				
			}
	
			for (j=0; j<object->nb_triangles; j++ )
				ply_get_element( file, &(object->tab_triangles[j]) ) ;
		
		}
		if ( strcmp( elem_names[i], "blue" ) == 0 ) {
			object->nb_triangles = nb ;
			object->tab_triangles = malloc ( object->nb_triangles * sizeof ( Ttriangle ) ) ;
		
			for ( j=0; j<nprops; j++ ) {
				printf("    -> Name: %s \n", prop[j]->name);
				if ( strcmp( prop[j]->name,"vertex_indices")==0 ) 
					 ply_get_property( file, "face", &faceProps[0] );	
				
			}
	
			for (j=0; j<object->nb_triangles; j++ )
				ply_get_element( file, &(object->tab_triangles[j]) ) ;
		
		}
	*/
	}
	
	return 0 ;

}
