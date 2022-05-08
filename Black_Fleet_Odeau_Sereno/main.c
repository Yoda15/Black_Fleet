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
#include "Module_Jeux/Déplacements.h"


int main()
{
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    HWND hwnd=GetForegroundWindow(); //Affichage
    ShowWindow(hwnd,SW_MAXIMIZE);    //En plein écran
    Joueur J[NBJ]; //Création Joueur
    S_Case P[Larg][Long]; //Création Plateau
    fregate F[2];
    int val_dep[CARTES+1]; //Valeur de déplacement de chaque bateau case 1:frégate, case 2:Pirate, case3:Marchand, case 4: couleur frégate

    //Test Matt
    int a;
    do{
      a=menu();
    switch (a){
    case 1:
        Initialisation(J,F);
        initialiser_Plateau(P);
        while(J[0].Pioche.Fin_Partie==0 && J[1].Pioche.Fin_Partie==0 && J[2].Pioche.Fin_Partie==0 && J[3].Pioche.Fin_Partie==0){
            for(int i; i<4; i++){
                J[i].doublons=12;
                Cartes_Aleatoire(val_dep);
                Deplacements(J,P,F,i,val_dep);
                Achat_Carte(&J[i]);
                printf("yes");
            }
        }
        break;
    case 2:
        //Regles();
        initialiser_Plateau(P);
        Affichage_Plateau(P,J);
        Sleep(20000);
        break;
    case 3:
        printf("3");
        Cartes_Aleatoire(val_dep);
        printf("%d", val_dep[0]);
        Sleep(10000);
        break;
    case 4:
        printf("Fermeture...");
        break;
    }
    }while((a!=1) && (a!=4));


    //Test Sim
    /*
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
