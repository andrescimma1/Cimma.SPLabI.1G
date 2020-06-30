#include "controller.h"
#include "eBicicleta.h"
#include "parser.h"


/** \brief Carga los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBicicleta)
{
    int r = 1;
    FILE* f = fopen(path, "r");

    if(f == NULL)
    {
        printf("Problema al abrir el archivo\n");
        r = -1;
    }
    else
    {
        r = parser_BicicletaFromText(f, pArrayListBicicleta);
    }

    fclose(f);

    return r;

}


/** \brief Guarda los datos de las bicicletas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBicicleta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBicicleta)
{
    int r = 1;
    int tam = ll_len(pArrayListBicicleta);
    FILE* f;
    eBicicleta* auxBicicleta;

    f = fopen(path, "w");

    if(f == NULL)
    {
        printf("Error al abrir el archivo\n\n");
    }
    else
    {
        fprintf(f, "id_bike,nombre,tipo,tiempo\n");

        for(int i=0; i<tam; i++)
        {
            auxBicicleta = (eBicicleta*)ll_get(pArrayListBicicleta, i);
            fprintf(f, "%d,%s,%s,%d\n", auxBicicleta->id_bike, auxBicicleta->nombre, auxBicicleta->tipo, auxBicicleta->tiempo);
            r = 1;
        }
    }

    if(r == 1)
    {
        printf("Se han guardado con exito!!\n\n");
    }

    fclose(f);

    return r;
}
