#include <stdio.h>
#include <stdlib.h>
#include "objet.h"

void initialiser_Plateau(S_Case P[][Long]);

S_Case P[Larg][Long];
void initialiser_Plateau(S_Case P[][Long])
{
    int i=0,j=0;
    //Initialisation mer
    for (i=0;i<Larg;i++)
    {
        for (j=0;j<Long;j++)
        {
            P[i][j].type=1;
            P[i][j].etat=0;
            P[i][j].bateau=0;
            P[i][j].joueur=0;
        }
    }
    //initialiser contour terre
    for (i=0;i<Long;i++)
    {
        P[0][i].type=0;
        P[Larg-1][i].type=0;
    }
    for (j=0;j<Larg;j++)
    {
        P[j][0].type=0;
        P[j][Long-1].type=0;
    }
    //initialiser case intérieure terre
    //coordonnées des cases terre
    int Ligne[20]={1,1,2,2,3,3,3,4,4,4,5,6,6,7,7,7,8,9,10,10};
    int Colonne[20]={4,8,11,12,1,2,6,5,9,11,7,1,4,4,7,9,10,5,3,11};
    for (i=0;i<20;i++)
    {
        P[Ligne[i]][Colonne[i]].type=0;
    }
    //initialiser case Trésor
    //coordonnées des cases Trésor
    int Ligne1[5]={3,3,7,7,8};
    int Colonne1[5]={5,9,3,10,9};
    for (i=0;i<5;i++)
    {
        P[Ligne1[i]][Colonne1[i]].type=3;
    }
    //initialiser case mer lointaine
    P[1][13].type=2;
    P[4][0].type=2;
    P[10][13].type=2;
    //initialiser case port outils
    P[0][6].type=4;
    P[0][7].type=4;
    //initialiser case port Riz
    P[0][2].type=5;
    P[0][3].type=5;
    //initialiser case port Blé
    P[9][0].type=6;
    P[10][0].type=6;
    //initialiser case port érable
    P[11][6].type=7;
    P[11][7].type=7;
    //initialiser case port vin
    P[5][13].type=8;
    P[6][13].type=8;
}

