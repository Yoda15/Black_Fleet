#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Objets.h"

//D�finition de l'objet "Joueur"
struct Joueur{
    char nom[NBCHAR]; //Nom du joueur
    int couleur; //Couleur (choix parmis les 16)
    int nb; //Num�ro de passage (0,1,2,3)
    int doublons; //nombre de doublons
    //struct Carte Pioche; //Carte d�tenu par le joueur
    //struct Bateau Boat; //Bateau d�tenu par le joueur
};
typedef struct Joueur Joueur;
/*
//D�finition de l'objet "Bateau"
struct Bateau{
};
*/
#endif // JOUEUR_H_INCLUDED
