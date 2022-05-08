#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED


#include "Declarations_Variables.h"
//Définition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au trésor, 4 Port outils, 5 port riz, 6 port blé, 7 port érable, 8 port vin
    int etat; // 0 si libre, 1 si occupé
    int bateau; // 0 Marchandise, 1 Pirates, 2 Frégates1, 3 Frégates2
    int joueur; // 0,1,2,3 (Par ordre de passage);
};
typedef struct Case S_Case;

//Définition de l'objet "Carte"
struct Carte{
    int dev[4]; // 1 si débloqué, 0 au contraire
    int Fin_Partie;
};

typedef struct Carte Carte;


//Définition de l'objet Marchands
struct Marchand{
    int joueur; //0,1,2,3 (Par Joueur)
    int statut; //Coulé(0) ou sur le plateau(1)
    int marchandise; //Nombre de marchandises: 0,1,2,3
    int type_marchandise; //Type de marchandise: 4,5,6,7,8
    int coordonee[2]; //Case occupée
};
typedef struct Marchand Marchand;

//Définition de l'objet pirates
struct Pirates{
    int joueur; //0,1,2,3 (Par Joueur)
    int statut; //Coulé(0) ou sur le plateau(1)
    int marchandise; //Nombre de marchandises: 0,1
    int coordonee[2]; //Case occupée
};
typedef struct Pirates Pirates;

//Définition de l'objet frégate
struct fregate{
    int coordonee[2]; //Case occupée
};
typedef struct fregate fregate;

//Définition de l'objet "Joueur"
struct Joueur{
    char nom[NBCHAR]; //Nom du joueur
    int couleur; //Couleur (choix parmis les 16)
    int nb; //Numéro de passage (0,1,2,3)
    int doublons; //nombre de doublons
    Carte Pioche; //Carte détenu par le joueur
    Marchand M;
    Pirates P;
};
typedef struct Joueur Joueur;



#endif // OBJETS_H_INCLUDED
