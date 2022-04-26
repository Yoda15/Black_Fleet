#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#define Long 14
#define Larg 12

//D�finition de l'objet "Case"
struct Case{
    int type; // 0 Terre, 1 Mer, 2 Mer lointaine, 3 cache au tr�sor, 4 Port outils, 5 port riz, 6 port bl�, 7 port �rable, 8 port vin
    int etat; // 0 si libre, 1 si occup�
    int bateau; // 1 Marchandise, 2 Pirates, 3 Fr�gates, 0 initialisation
    int joueur; // 1,2,3,4 (Par ordre de passage); 0 initialisation
};
typedef struct Case S_Case;

void initialiser_Plateau(S_Case P[][Long]);


#endif // OBJET_H_INCLUDED
