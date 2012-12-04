### CMake file for ply_viewer library
###
###   - July 2012: Initial version <druon@lirmm.fr>
###
###
###############################################################################


cmake_minimum_required (VERSION 2.6)


project (vision)
set (vision_VERSION_MAJOR 0)
set (vision_VERSION_MINOR 1)

set( CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /lib /usr/lib /usr/local/lib )
set( CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/include /usr/local/include )
set( CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH}  "${PROJECT_SOURCE_DIR}/cmake" ) 

set ( INSTALL_BIN_PATH bin )
set ( INSTALL_LIB_PATH lib )
set ( INSTALL_AR_PATH  lib )
set ( INSTALL_HEADERS_PATH include )


# Make relative paths absolute (needed later on)

foreach(p LIB BIN HEADERS AR)
	set(var INSTALL_${p}_PATH)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()



### Search for Lib/Headers

# find_package( Eigen3 2.9)

### Set include directories 
        
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/src"
		     "${CMAKE_CURRENT_SOURCE_DIR}/src/ply"
	             "${CMAKE_CURRENT_BINARY_DIR}" )

### File Lists

file( GLOB src "src/*.c*" "src/ply/*.c*" )
file( GLOB hdr "src/*.h*" "src/ply/*.h*" )


### Targets

add_executable( "ply_viewer" ${src}  ${hdr} )

# target_link_libraries( "ply_viewer" ${Boost_LIBRARIES} )


install( TARGETS "ply_viewer"
	    RUNTIME DESTINATION ${INSTALL_BIN_PATH}  COMPONENT main
	    LIBRARY DESTINATION ${INSTALL_LIB_PATH}  COMPONENT main
	    ARCHIVE DESTINATION ${INSTALL_AR_PATH}   COMPONENT main )
        

