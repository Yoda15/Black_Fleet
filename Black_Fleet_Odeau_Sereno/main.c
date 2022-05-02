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
    Joueur J[NBJ];
    S_Case P[Larg][Long];
    do{
      a=menu();
    switch (a){
    case 1:
        Initialisation(J);
        initialiser_Plateau(P);
        break;
    case 2:
        Regles();
        break;
    case 3:
        printf("3");
        break;
    default:
        printf("default");
        break;
    }
    }while(a!=1);


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
