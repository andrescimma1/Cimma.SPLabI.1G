#include "parser.h"
#include "eBicicleta.h"

/** \brief Parsea los datos los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListAvion LinkedList*
 * \return int
 *
 */
int parser_BicicletaFromText(FILE* pFile , LinkedList* pArrayListBicicleta)
{
    int cant;
    int r = -1;
    char buffer[4][1500];
    eBicicleta* auxBicicleta;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant == 4)
        {
            auxBicicleta = bicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            if(auxBicicleta != NULL)
            {
                ll_add(pArrayListBicicleta, auxBicicleta);
                r = 1;
            }
        }
    }

    if(r == 1)
    {
        printf("\nBicicletas cargados con exito!!\n\n");
    }
    else
    {
        printf("\nProblemas con el archivo\n");
    }

    return r;
}
