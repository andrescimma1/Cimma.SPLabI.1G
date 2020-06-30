#ifndef EBICICLETA_H_INCLUDED
#define EBICICLETA_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;

int getRandom();
int menu();
eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametros(char* idBikeStr,char* nombreStr,char* tipoStr, char* tiempoStr);
int bicicleta_setIdBike(eBicicleta* this,int idBike);
int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int mostrarBicicleta(eBicicleta* bicicleta);
int mostrarBicicletas(LinkedList* lista);
int filtrarPorBMX(void* unaBicicleta);
int filtrarPorPLAYERA(void* unaBicicleta);
int filtrarPorMTB(void* unaBicicleta);
int filtrarPorPASEO(void* unaBicicleta);
int asignarTiempo(void* unaBicicleta);
int compararBicicletasTipoYTiempo(void* bic1, void* bic2);

#endif // EBICICLETA_H_INCLUDED
