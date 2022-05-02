#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Declarations_Variables.h"
#include "Objets.h"
#include "Fonctions_Initialisation.h"
#include "Affichage/Plateau.h"
#include "Menu.h"

int main()
{
    //Test Matt
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    int a;
    a=menu();

    /*int NBJ =4;
    Joueur J[NBJ];
    Initialisation(J, NBJ);*/


    //Test Sim
    /*
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
    */
}
