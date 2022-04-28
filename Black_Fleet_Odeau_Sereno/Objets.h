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

#endif // OBJETS_H_INCLUDED
