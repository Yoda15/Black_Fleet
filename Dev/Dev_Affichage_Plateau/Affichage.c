#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "objet.h"
#include "Affichage.h"

void Affichage_Plateau(S_Case P[][Long]);

S_Case P[Larg][Long];
void Affichage_Plateau(S_Case P[][Long])
{
    int i=0,j=0;
    int k=0;
    for (i=0; i<Larg; i++)
    {
        for (j=0; j<Long; j++)
        {
            printf("|");
            switch(P[i][j].type)
            {
            case 0:
                color(2,2);
                break;
            case 2:
                color(1,1);
                break;
            case 3:
                color(14,14);
                break;
            case 4:
                color(3,3);
                break;
            case 5:
                color(10,10);
                break;
            case 6:
                color(12,12);
                break;
            case 7:
                color(5,5);
                break;
            case 8:
                color(4,4);
                break;
            default:color(9,9);

            }
            printf("%6d",P[i][j].type);
            color(15,0);
        }
        printf("\n");
        for(k=0;k<98;k++)
        {
            printf("-");
        }
        printf("\n");
    }
}



void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
