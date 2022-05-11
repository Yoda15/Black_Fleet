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
#include "Module_Jeux/Placements.h"
#include "Module_Jeux/Fin_Partie.h"

int main()
{
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    HWND hwnd=GetForegroundWindow(); //Affichage
    ShowWindow(hwnd,SW_MAXIMIZE);    //En plein écran
    Joueur J[NBJ]; //Création Joueur
    S_Case P[Larg][Long]; //Création Plateau
    fregate F[2];
    int val_dep[CARTES+1]; //Valeur de déplacement de chaque bateau case 1:frégate, case 2:Pirate, case3:Marchand, case 4: couleur frégate
    int a,i;
    do{
      a=menu();
    switch (a){
    case 1:
        //Initialiser Types Structurés
        Initialisation(J,F);
        initialiser_Plateau(P);
        //Placement Initial Bateau
        for(i=0;i<4;i++){
            Placement_Bateau(&J[i],P,F);
        }
        while(J[0].Pioche.Fin_Partie==0 && J[1].Pioche.Fin_Partie==0 && J[2].Pioche.Fin_Partie==0 && J[3].Pioche.Fin_Partie==0){
            for(i=0; i<4; i++){ //Tour
                Placement_Bateau(&J[i],P, F);
                Cartes_Aleatoire(val_dep,J[i]);
                Deplacements(J,P,F,i,val_dep);
                Achat_Carte(&J[i]);
            }
        }
        Fin_de_partie(J);
        break;
    case 2:
        Regles();
        break;
    case 3:
        system("cls");
        printf("|------------------------------Black Fleet------------------------------|\n");
        printf("                      ODEAU Simon & SERENO Matthieu");
        Sleep(5000);
        break;
    case 4:
        printf("Fermeture...");
        Sleep(1000);
        break;
    }
    }while((a!=1) && (a!=4));
    return 0;
}
