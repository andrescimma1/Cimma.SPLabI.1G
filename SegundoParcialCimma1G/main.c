#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "eBicicleta.h"


int main()
{
    int r;
    char seguir;
    char archivo[20];
    char tipo[20];

    srand (time(NULL));

    LinkedList* lista;
    LinkedList* listaFiltradaXTipo;
    LinkedList* listaAsignada;

    lista = ll_newLinkedList();

     do
    {
        switch(menu())
        {
            case 1: printf("\nIngrese el nombre del archivo que desea cargar (Ej: bicicletas.csv): ");
                    fflush(stdin);
                    gets(archivo);
                    r = controller_loadFromText(archivo, lista);
                    if(r == -1)
                    {
                        printf("No se pudo leer el archivo\n\n");
                        exit(EXIT_FAILURE);
                    }
                    break;

            case 2: mostrarBicicletas(lista);
                    break;

            case 3: listaAsignada = ll_newLinkedList();
                    listaAsignada = ll_map(lista, asignarTiempo);
                    mostrarBicicletas(listaAsignada);
                    controller_saveAsText("listaTiempo.csv", listaAsignada);
                    printf("Se genero un archivo llamado: listaTiempo.csv");
                    break;

            case 4: printf("TIPOS: BMX    PLAYERA    MTB    PASEO\n\n");
                    printf("Ingrese tipo (en mayuscula): ");
                    fflush(stdin);
                    gets(tipo);

                    if(strcmp(tipo, "BMX") == 0)
                    {
                        listaFiltradaXTipo = ll_newLinkedList();
                        listaFiltradaXTipo = ll_filter(lista, filtrarPorBMX);
                        mostrarBicicletas(listaFiltradaXTipo);
                        controller_saveAsText("listaBMX.csv", listaFiltradaXTipo);
                        printf("Se genero un archivo llamado: listaBMX.csv\n\n");
                    }
                    if(strcmp(tipo, "PLAYERA") == 0)
                    {
                        listaFiltradaXTipo = ll_newLinkedList();
                        listaFiltradaXTipo = ll_filter(lista, filtrarPorPLAYERA);
                        mostrarBicicletas(listaFiltradaXTipo);
                        controller_saveAsText("listaPLAYERA.csv", listaFiltradaXTipo);
                        printf("Se genero un archivo llamado: listaPLAYERA.csv\n\n");
                    }
                    if(strcmp(tipo, "MTB") == 0)
                    {
                        listaFiltradaXTipo = ll_newLinkedList();
                        listaFiltradaXTipo = ll_filter(lista, filtrarPorMTB);
                        mostrarBicicletas(listaFiltradaXTipo);
                        controller_saveAsText("listaMTB.csv", listaFiltradaXTipo);
                        printf("Se genero un archivo llamado: listaMTB.csv\n\n");
                    }
                    if(strcmp(tipo, "PASEO") == 0)
                    {
                        listaFiltradaXTipo = ll_newLinkedList();
                        listaFiltradaXTipo = ll_filter(lista, filtrarPorPASEO);
                        mostrarBicicletas(listaFiltradaXTipo);
                        controller_saveAsText("listaPASEO.csv", listaFiltradaXTipo);
                        printf("Se genero un archivo llamado: listaPASEO.csv\n\n");
                    }
                    break;

            case 5: ll_sort(lista, compararBicicletasTipoYTiempo, 0);
                    printf("Lista ordenada!!\n\n");
                    break;

            case 6: r = controller_saveAsText("listaOrdenada.csv", lista);
                    if(r == -1)
                    {
                        printf("No se pudo guardar el archivo\n\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        printf("\nSe genero un archivo llamado: listaOrdenada.csv\n\n");
                    }
                    break;

            case 7: printf("Seguro que desea salir? s/n: ");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    break;

            default: printf("Error, opcion incorrecta\n\n");
                     break;

        }
    }while(seguir != 's');


    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaFiltradaXTipo);
    ll_deleteLinkedList(listaAsignada);
    return 0;
}


