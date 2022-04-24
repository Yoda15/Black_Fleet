#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED


#include "Declarations_Variables.h"
//D�finition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au tr�sor, 4 Port
    int etat; // 0 si libre, 1 si occup�
    int bateau; // 0 Marchandise, 1 Pirates, 2 Fr�gates
    int joueur; // 0,1,2,3 (Par ordre de passage)
};



//D�finition de l'objet "Carte"
struct Carte{
    int dev1; // 1 si d�bloqu�, 0 au contraire
    int dev2;
    int dev3;
    int dev4;
    int Fin_Partie;
};


#endif // OBJETS_H_INCLUDED
