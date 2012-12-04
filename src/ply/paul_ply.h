#ifndef _PAUL_PLY_H
#define _PAUL_PLY_H

#include <stdio.h>
#include <stdlib.h>

#include "rigidobject.h"

double* allocmem(int size_type);


int rigidobject_loadply(Trigidobject* object, char* filename);

#endif
