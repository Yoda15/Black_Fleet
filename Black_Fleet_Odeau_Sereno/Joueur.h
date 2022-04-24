#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Objets.h"

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
#endif // JOUEUR_H_INCLUDED
