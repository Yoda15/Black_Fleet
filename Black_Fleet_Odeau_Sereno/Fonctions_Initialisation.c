#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Declarations_Variables.h"
#include "Objets.h"
#include "Fonctions_Initialisation.h"
#include "Affichage/Couleurs.h"



int Choix_Couleur(int *c){
    /**Choix de la Couleur**/
    int colora=-1;
    while (((colora!=0) && (colora!=6) && (colora!=7) && (colora!=8) && (colora!=11) && (colora!=13) && (colora!=15)) || (c[colora]==-1)){ //Permet de vérifier que la couleur sélectionner est compris entre 1 et 15 et qu'elle n'a pas déjà était sélectionné ou indisponible
        printf("\nVeuillez Choisir une couleur : ");
        printf("\n -Noir 0\n -Marron 6\n -Gris(Clair) 7\n -Gris(Foncé) 8\n -Cyan(Clair) 11\n -Magenta(Clair) 13\n -Blanc 15\n");
        printf("\nNuméro de la Couleur: ");
        scanf("%d", &colora);
        if (c[colora]==-1){
            color(4,0);
            printf("Couleur Déjà Selectionné ! Merci d'en choisir une autre.");
            color(15,0);
        }
        printf("%d", colora);
    }
    c[colora]=-1;
    return colora;
}


void Initialisation(Joueur J[]){
    /**Initialisation de l'objet "Joueur"**/
    int c_couleur[16];
    int i;
    for(i=0; i<16; i++){ //Création d'un tableau ayant les 16 valeurs de couleur (non définie)
        c_couleur[i]=-1;
    }
    //Initialisation des couleurs disponible
    c_couleur[0]=0;
    c_couleur[6]=6;
    c_couleur[7]=7;
    c_couleur[8]=8;
    c_couleur[11]=11;
    c_couleur[13]=13;
    c_couleur[15]=15;
    for(i=0; i<NBJ; i++){ //Boucle permettant de compléter la structure de chaque joueur
        printf("\nVeuillez Rentrer le nom du joueur n°%d: ", i+1);
        scanf("%s", J[i].nom); //choix du nom
        J[i].couleur=(Choix_Couleur(c_couleur)); //choix de la couleur
        J[i].nb=0;
        J[i].doublons=0;
        J[i].M.joueur=i;
        J[i].M.marchandise=0;
        J[i].M.statut=0;
        J[i].M.type_marchandise=0;
        J[i].M.coordonee[0]=20;
        J[i].M.coordonee[1]=20;
        J[i].P.joueur=i;
        J[i].P.marchandise=0;
        J[i].P.statut=0;
        J[i].P.coordonee[0]=20;
        J[i].P.coordonee[1]=20;
    }
}


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


