#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "Affichage.h"
int main()
{
    S_Case P[Larg][Long];
    int i=0,j=0;
    initialiser_Plateau(P);
     for (i=0;i<Larg;i++)
    {
        for (j=0;j<Long;j++)
        {
            printf(" %d ",P[i][j].type);
        }
        printf("\n");
    }
    Affichage_Plateau(P);
    return 0;
}
