#include "eBicicleta.h"




int getRandom()
{
    int aleatorio;

    aleatorio = rand()%(71)+50;

    return aleatorio;
}



/** \brief Crea un puntero a bicicleta en la memoria dinamica y lo inicializa todo en 0 o "".
 *
 * \param eBicicleta* newBicicleta;
 * \param
 * \return newBicicleta;
 *
 */
eBicicleta* bicicleta_new()
{
    eBicicleta* newBicicleta;
    newBicicleta = (eBicicleta*)malloc(sizeof(eBicicleta));

    if(newBicicleta != NULL)
    {
        newBicicleta->id_bike = 0;
        strcpy(newBicicleta->nombre, "");
        strcpy(newBicicleta->tipo, "");
        newBicicleta->tiempo = 0;
    }

    return newBicicleta;
}



/** \brief Crea un puntero a bicicleta y valida los datos.
 *
 * \param eBicicleta* newBicicleta;
 * \param
 * \return newBicicleta;
 *
 */
eBicicleta* bicicleta_newParametros(char* idBikeStr,char* nombreStr,char* tipoStr, char* tiempoStr)
{
    eBicicleta* newBicicleta;

    newBicicleta = bicicleta_new();

    if(newBicicleta != NULL)
    {
        if(bicicleta_setIdBike(newBicicleta, atoi(idBikeStr))
        || bicicleta_setNombre(newBicicleta, nombreStr)
        || bicicleta_setTipo(newBicicleta, tipoStr)
        || bicicleta_setTiempo(newBicicleta, atoi(tiempoStr)))
        {
            free(newBicicleta);
            newBicicleta = NULL;
        }
    }

    return newBicicleta;
}




/** \brief Valida el idBike puesto como segundo parámetro y se lo asigna a la bicicleta
 *
 * \param int error = 1;
 * \param
 * \return error;
 *
 */
int bicicleta_setIdBike(eBicicleta* this,int idBike)
{
    int error = 1;

    if(this != NULL && idBike >= 0 && idBike <= 20000)
    {
        this->id_bike = idBike;
        error = 0;
    }

    return error;
}




/** \brief Valida el nombre puesto como segundo parámetro y se lo asigna a la bicicleta
 *
 * \param int error = 1;
 * \param
 * \return error;
 *
 */
int bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20)
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}



/** \brief Valida el tipo puesto como segundo parámetro y se lo asigna a la bicicleta
 *
 * \param int error = 1;
 * \param
 * \return error;
 *
 */
int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int error = 1;

    if(this != NULL && strlen(tipo) >= 3 && strlen(tipo) < 20)
    {
        strcpy(this->tipo, tipo);
        error = 0;
    }

    return error;
}




/** \brief Valida el tiempo puesto como segundo parámetro y se lo asigna a la bicicleta
 *
 * \param int error = 1;
 * \param
 * \return error;
 *
 */
int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int error = 1;

    if(this != NULL && tiempo >= 0 && tiempo <= 20000)
    {
        this->tiempo = tiempo;
        error = 0;
    }

    return error;
}



/** \brief Crea un menú de opciones y devuelve la opcion elegida
 *
 * \param int opcion;
 * \param
 * \return opcion;
 *
 */
int menu()
{
    int opcion;

    printf("*** MENU DE OPCIONES ***\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar posiciones\n");
    printf("6. Guardar posiciones\n");
    printf("7. Salir\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




/** \brief Muestra una bicicleta
 *
 * \param int error = 1;
 * \param
 * \return error;
 *
 */
int mostrarBicicleta(eBicicleta* bicicleta)
{
    int error = 1;


    if(bicicleta != NULL)
    {
        printf("%d        %12s        %12s         %d\n", bicicleta->id_bike, bicicleta->nombre, bicicleta->tipo, bicicleta->tiempo);
        error = 0;
    }

    return error;
}




/** \brief Muestra las bicicletas de la lista.
 *
 * \param int r = -1;
 * \param int flag = 0;
 * \param int tam = ll_len(lista);
 * \param eBicicleta* auxBicicleta;
 * \return r;
 *
 */
int mostrarBicicletas(LinkedList* lista)
{
    int r = -1;
    int flag = 0;

    int tam = ll_len(lista); //Contiene el tamaño de la lista
    eBicicleta* auxBicicleta;

    if(lista != NULL)
    {
        printf("ID             NOMBRE                TIPO           TIEMPO\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxBicicleta = (eBicicleta*)ll_get(lista, i); //Mediante el indice obtiene la ubicacion del avion
            if(auxBicicleta != NULL)
            {
                mostrarBicicleta(auxBicicleta);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay bicicletas para mostrar\n");
        }
        printf("\n\n");
        r = 1;
    }

    return r;
}




/** \brief Pide al usuario el tipo de la bicicleta y lo filtra por ese tipo
 *
 * \param int auxReturn = 0;
 * \param eBicicleta* x;
 * \param char tipo[20];
 * \return
 *
 */
int filtrarPorBMX(void* unaBicicleta)
{
    int auxReturn = 0;
    eBicicleta* x;
    char tipoStr[20];


    strcpy(tipoStr, "BMX");

    if(unaBicicleta != NULL)
    {
        x = (eBicicleta*)unaBicicleta;

        if(strcmp(x->tipo, tipoStr) == 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}



/** \brief Pide al usuario el tipo de la bicicleta y lo filtra por ese tipo
 *
 * \param int auxReturn = 0;
 * \param eBicicleta* x;
 * \param char tipo[20];
 * \return
 *
 */
int filtrarPorPLAYERA(void* unaBicicleta)
{
    int auxReturn = 0;
    eBicicleta* x;
    char tipoStr[20];


    strcpy(tipoStr, "PLAYERA");

    if(unaBicicleta != NULL)
    {
        x = (eBicicleta*)unaBicicleta;

        if(strcmp(x->tipo, tipoStr) == 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}



/** \brief Pide al usuario el tipo de la bicicleta y lo filtra por ese tipo
 *
 * \param int auxReturn = 0;
 * \param eBicicleta* x;
 * \param char tipo[20];
 * \return
 *
 */
int filtrarPorMTB(void* unaBicicleta)
{
    int auxReturn = 0;
    eBicicleta* x;
    char tipoStr[20];


    strcpy(tipoStr, "MTB");

    if(unaBicicleta != NULL)
    {
        x = (eBicicleta*)unaBicicleta;

        if(strcmp(x->tipo, tipoStr) == 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}



/** \brief Pide al usuario el tipo de la bicicleta y lo filtra por ese tipo
 *
 * \param int auxReturn = 0;
 * \param eBicicleta* x;
 * \param char tipo[20];
 * \return
 *
 */
int filtrarPorPASEO(void* unaBicicleta)
{
    int auxReturn = 0;
    eBicicleta* x;
    char tipoStr[20];


    strcpy(tipoStr, "PASEO");

    if(unaBicicleta != NULL)
    {
        x = (eBicicleta*)unaBicicleta;

        if(strcmp(x->tipo, tipoStr) == 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}



/** \brief Asigna los tiempos a las bicicletas
 *
 * \param int auxReturn = 0;
 * \param int aleatorio;
 * \param eBicicleta* x;
 * \return
 *
 */
int asignarTiempo(void* unaBicicleta)
{
    int auxReturn = 0;
    int aleatorio;
    eBicicleta* x;

    if(unaBicicleta != NULL)
    {
        x = (eBicicleta*)unaBicicleta;

        aleatorio = getRandom();

        x->tiempo = aleatorio;

        if(x->tiempo > 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}




/** \brief Compara el el tipo y tiempo
 *
 * \param int rta;
 * \param eBicicleta* a = (eBicicleta*)bic1;
 * \param eBicicleta* b = (eBicicleta*)bic2;
 * \return rta;
 *
 */
int compararBicicletasTipoYTiempo(void* bic1, void* bic2)
{
    int rta;
    eBicicleta* a = (eBicicleta*)bic1;
    eBicicleta* b = (eBicicleta*)bic2;

    if(strcmp(a->tipo, b->tipo) == 0)
    {
        if(a->tiempo > b->tiempo)
        {
            rta = -1;
        }
        else
        {
            rta = 1;
        }
    }
    else if(strcmp(a->tipo, b->tipo) < 1)
    {
        rta = -1;
    }
    else
    {
        rta = 1;
    }

    return rta;
}
