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
#include "Module_Jeux/Message.h"
#include "Fichiers.h"
#include "Option.h"

int main()
{
    system("Stop_Musique.bat");
    system("cls");
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    HWND hwnd=GetForegroundWindow(); //Affichage
    ShowWindow(hwnd,SW_MAXIMIZE);    //En plein écran
    Affichage_Fichier_SON();
    Messages(19);
    Sleep(2000);
    Joueur J[NBJ]; //Création Joueur
    S_Case P[Larg][Long]; //Création Plateau
    fregate F[2];
    int val_dep[CARTES+1]; //Valeur de déplacement de chaque bateau case 1:frégate, case 2:Pirate, case3:Marchand, case 4: couleur frégate
    int a,i,nbj=4,difficulte=1,vitesse=1;
    system("Musique_Menu.bat");
    do{
      a=menu();
    switch (a){
    case 1:
        //Initialiser Types Structurés
        Option(&nbj,&difficulte,&vitesse);
        Initialisation(J,F);
        initialiser_Plateau(P);
        //Placement Initial Bateau
        for(i=0;i<4;i++){
            Placement_Bateau(&J[i],P,F);
            if(vitesse==2){
                J[i].Pioche.dev[2]=1;
                J[i].Pioche.dev[3]=1;
            }
            else if(vitesse==3){
                J[i].Pioche.dev[0]=1;
                J[i].Pioche.dev[1]=1;
                J[i].Pioche.dev[2]=1;
                J[i].Pioche.dev[3]=1;
            }
        }
        system("Stop_Musique.bat");
        system("Musique_Jeu.bat");
        while(J[0].Pioche.Fin_Partie==0 && J[1].Pioche.Fin_Partie==0 && J[2].Pioche.Fin_Partie==0 && J[3].Pioche.Fin_Partie==0){
            for(i=0; i<4; i++){ //Tour
                Placement_Bateau(&J[i],P, F);
                Cartes_Aleatoire(val_dep,J[i]);
                Deplacements(J,P,F,i,val_dep);
                Achat_Carte(&J[i]);
                if(difficulte==2){
                    Messages(22);
                    J[i].doublons--;
                }
                else if(difficulte==3){
                    Messages(22);
                    J[i].doublons=J[i].doublons-3;
                }
            }
        }
        Fin_de_partie(J);
        system("Stop_Musique.bat");
        break;
    case 2:
        Regles();
        break;
    case 3:
        system("cls");
        printf("|------------------------------Black Fleet------------------------------|\n");
        printf("                      ODEAU Simon & SERENO Matthieu");
        Affichage_Fichier_ESTACA();
        printf("\nAppuyer sur ESPACE pour revenir au Menu Principal...");
        boucle_verif();
        break;
    case 4:
        printf("Fermeture...");
        Sleep(1000);
        system("Stop_Musique.bat");
        break;
    }
    }while((a!=1) && (a!=4));
    return 0;
}
