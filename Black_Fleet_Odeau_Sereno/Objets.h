#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED


#include "Declarations_Variables.h"
//D�finition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au tr�sor, 4 Port outils, 5 port riz, 6 port bl�, 7 port �rable, 8 port vin
    int etat; // 0 si libre, 1 si occup�
    int bateau; // 1 Marchandise, 2 Pirates, 3 Fr�gates, 0 initialisation
    int joueur; // 1,2,3,4 (Par ordre de passage); 0 initialisation
};
typedef struct Case S_Case;

//D�finition de l'objet "Carte"
struct Carte{
    int dev1; // 1 si d�bloqu�, 0 au contraire
    int dev2;
    int dev3;
    int dev4;
    int Fin_Partie;
};

typedef struct Carte Carte;

#endif // OBJETS_H_INCLUDED
