#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../Declarations_Variables.h"
#include "../Objets.h"
#include "Couleurs.h"



void Affichage_Plateau(S_Case P[][Long],Joueur J[],fregate F[]);
void Affichage_Bateau(S_Case P[][Long],fregate F[],int i,int j,Joueur J[],int c);


S_Case P[Larg][Long];
void Affichage_Plateau(S_Case P[][Long],Joueur J[],fregate F[])
{
    int i=0,j=0,k=0,c=0;
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
                c=1;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 3:
                c=14;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 4:
                c=3;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 5:
                c=10;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 6:
                c=12;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 7:
                c=5;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 8:
                c=4;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            default:
                c=9;
                Affichage_Bateau(P,F,i,j,J,c);

            }
            printf("%10d",P[i][j].type);
            color(15,0);
        }
        printf("\n");
        for(k=0;k<((10*Long)+Long);k++)
        {
            printf("-");
        }
        printf("\n");
    }
}

void Affichage_Bateau(S_Case P[][Long],fregate F[],int i,int j,Joueur J[],int c)
{
    char t[2];
    if(P[i][j].etat==0)
    {

    }
    else
    {
        switch(P[i][j].bateau)
        {
        case 0:
            color(J[(P[i][j].joueur)].couleur,c);
            nom_couleur(J[(P[i][j].joueur)],t);
            printf(" Mar-%d-%s ",J[(P[i][j].joueur)].M.marchandise,t);
            break;
        case 1:
            color(J[(P[i][j].joueur)].couleur,c);
             printf(" Pirate-%d ",J[(P[i][j].joueur)].P.marchandise);
            break;
        case 2:
            color(F[].couleur,c);
            printf(" Frégate  ");
            break;


        }
    }
}



