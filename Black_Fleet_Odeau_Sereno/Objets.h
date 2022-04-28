#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED


#include "Declarations_Variables.h"
//Définition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au trésor, 4 Port outils, 5 port riz, 6 port blé, 7 port érable, 8 port vin
    int etat; // 0 si libre, 1 si occupé
    int bateau; // 1 Marchandise, 2 Pirates, 3 Frégates, 0 initialisation
    int joueur; // 1,2,3,4 (Par ordre de passage); 0 initialisation
};
typedef struct Case S_Case;

//Définition de l'objet "Carte"
struct Carte{
    int dev1; // 1 si débloqué, 0 au contraire
    int dev2;
    int dev3;
    int dev4;
    int Fin_Partie;
};

typedef struct Carte Carte;

//Définition de l'objet "Joueur"
struct Joueur{
    char nom[NBCHAR]; //Nom du joueur
    int couleur; //Couleur (choix parmis les 16)
    int nb; //Numéro de passage (0,1,2,3)
    int doublons; //nombre de doublons
    //struct Carte Pioche; //Carte détenu par le joueur
    //struct Bateau Boat; //Bateau détenu par le joueur
};
typedef struct Joueur Joueur;
/*
//Définition de l'objet "Bateau"
struct Bateau{
};
*/

#endif // OBJETS_H_INCLUDED
