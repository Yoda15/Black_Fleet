#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Declarations_Variables.h"
#include "Objets.h"
#include "Fonctions_Initialisation.h"
#include "Affichage/Plateau.h"
#include "Menu.h"
#include "Module_Jeux/Cartes.h"


int main()
{
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    HWND hwnd=GetForegroundWindow(); //Affichange
    ShowWindow(hwnd,SW_MAXIMIZE);    //En plein écran
    Joueur J[NBJ];
    S_Case P[Larg][Long];
    //Test Matt
    /*
    int a;
    do{
      a=menu();
    switch (a){
    case 1:
        Initialisation(J);
        initialiser_Plateau(P);
        Achat_Carte(J[0]);
        while(J[0].Pioche.Fin_Partie==0 && J[1].Pioche.Fin_Partie==0 && J[2].Pioche.Fin_Partie==0 && J[3].Pioche.Fin_Partie==0){
            J[0].Pioche.Fin_Partie=1;
            printf("yes");
        }
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
    */


    //Test Sim
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
