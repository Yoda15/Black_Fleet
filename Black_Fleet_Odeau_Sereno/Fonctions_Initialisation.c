#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Declarations_Variables.h"
#include "Objets.h"
#include "Joueur.h"
#include "Fonctions_Initialisation.h"
#include "Affichage/Couleurs.h"


int Choix_Couleur(int *c);


void Initialisation(Joueur J[]){
    /**Initialisation de l'objet "Joueur"**/
    int c_couleur[16];
    int i;
    for(i=0; i<16; i++){ //Création d'un tableau ayant les 16 valeurs de couleur
        c_couleur[i]=i;
    }
    for(i=0; i<NBJ; i++){ //Boucle permettant de compléter la structure de chaque joueur
        printf("\nVeuillez Rentrer le nom du joueur n°%d: ", i+1);
        scanf("%s", J[i].nom); //choix du nom
        J[i].couleur=(Choix_Couleur(c_couleur)); //choix de la couleur
        J[i].nb=0;
        J[i].doublons=0;
    }
}


int Choix_Couleur(int *c){
    /**Choix de la Couleur**/
    int colora=0;
    while ((colora<1) || (colora>15)|| (c[colora]==0)){ //Permet de vérifier que la couleur sélectionner est compris entre 1 et 15 et qu'elle n'a pas déjà était sélectionné
        printf("\nVeuillez Choisir une couleur : ");
        printf("\n -Bleu 1\n -Vert 2\n -Cyan 3\n -Rouge 4\n -Magenta 5\n -Marron 6\n -Gris(Clair) 7\n -Gris(Foncé) 8\n -Bleu(Clair) 9\n -Vert(Clair) 10\n -Cyan(Clair) 11\n -Rouge(Clair) 12\n -Magenta(Clair) 13\n -Jaune 14\n -Blanc 15\n");
        printf("\nNuméro de la Couleur: ");
        scanf("%d", &colora);
        if (c[colora]==0){
            color(4,0);
            printf("Couleur Déjà Selectionné ! Merci d'en choisir une autre.");
            color(15,0);
        }
    }
    c[colora]=0;
    return colora;
}
