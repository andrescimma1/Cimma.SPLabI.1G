#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBicicleta);
int controller_saveAsText(char* path , LinkedList* pArrayListBicicleta);

#endif // CONTROLLER_H_INCLUDED
