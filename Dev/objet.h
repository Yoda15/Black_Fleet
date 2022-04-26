#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#define Long 14
#define Larg 12

//Définition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au trésor, 4 Port outils, 5 port riz, 6 port blé, 7 port érable, 8 port vin
    int etat; // 0 si libre, 1 si occupé
    int bateau; // 1 Marchandise, 2 Pirates, 3 Frégates, 0 initialisation
    int joueur; // 1,2,3,4 (Par ordre de passage); 0 initialisation
};
typedef struct Case S_Case;

void initialiser_Plateau(S_Case P[][Long]);


#endif // OBJET_H_INCLUDED
