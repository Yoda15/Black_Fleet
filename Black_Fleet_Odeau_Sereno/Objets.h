#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED


#include "Declarations_Variables.h"
//D�finition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au tr�sor, 4 Port outils, 5 port riz, 6 port bl�, 7 port �rable, 8 port vin
    int etat; // 0 si libre, 1 si occup�
    int bateau; // 0 Marchandise, 1 Pirates, 2 Fr�gates1, 3 Fr�gates2
    int joueur; // 0,1,2,3 (Par ordre de passage);
};
typedef struct Case S_Case;

//D�finition de l'objet "Carte"
struct Carte{
    int dev[4]; // 1 si d�bloqu�, 0 au contraire
    int Fin_Partie;
};

typedef struct Carte Carte;


//D�finition de l'objet Marchands
struct Marchand{
    int joueur; //0,1,2,3 (Par Joueur)
    int statut; //Coul�(0) ou sur le plateau(1)
    int marchandise; //Nombre de marchandises: 0,1,2,3
    int type_marchandise; //Type de marchandise: 4,5,6,7,8
    int coordonee[2]; //Case occup�e
};
typedef struct Marchand Marchand;

//D�finition de l'objet pirates
struct Pirates{
    int joueur; //0,1,2,3 (Par Joueur)
    int statut; //Coul�(0) ou sur le plateau(1)
    int marchandise; //Nombre de marchandises: 0,1
    int coordonee[2]; //Case occup�e
};
typedef struct Pirates Pirates;

//D�finition de l'objet fr�gate
struct fregate{
    int coordonee[2]; //Case occup�e
};
typedef struct fregate fregate;

//D�finition de l'objet "Joueur"
struct Joueur{
    char nom[NBCHAR]; //Nom du joueur
    int couleur; //Couleur (choix parmis les 16)
    int nb; //Num�ro de passage (0,1,2,3)
    int doublons; //nombre de doublons
    Carte Pioche; //Carte d�tenu par le joueur
    Marchand M;
    Pirates P;
};
typedef struct Joueur Joueur;



#endif // OBJETS_H_INCLUDED
