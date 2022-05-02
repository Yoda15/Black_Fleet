#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Declarations_Variables.h"
#include "Objets.h"
#include "Fonctions_Initialisation.h"
#include "Affichage/Plateau.h"
#include "Menu.h"
#include "Affichage/Couleurs.h"


int menu(){
    int i;
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                        |\n");
    printf("|-----------------------------------------------Black Fleet----------------------------------------------|\n");
    printf("|                                                                                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                               1-> Jouer                                                |\n");
    printf("|                                               2-> Règles                                               |\n");
    printf("|                                               3-> Crédits                                              |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("                                                                                                          \n");
    printf("Choisisez une option : ");
    scanf("%d",&i);
    if ((i<1) || (i>3)){
        color(4,0);
        printf("\nMerci de Choisir une option entre 1 et 3 !!!");
        color(15,0);
        Sleep(2000);
    }

    }while((i<1) || (i>3));
    return i;
}

void Regles()
{
    printf("BUT DU JEU : ");
    printf("déverrouiller 4 cartes développement puis une carte victoire pour gagner la partie.\n");
    printf("Chaque carte développement coute un certain nombre de doublons (5, 8, 11, 14) et la carte victoire coute 10 doublons.\n");
    printf("En cas d’égalité (si 2 joueurs débloquent la carte victoire sur le même tour),\n");
    printf("celui qui a le plus de doublons a la fin du tour final gagne.\n");
    printf("Pour gagner des doublons il y a trois possibilités :\n");
    printf("vendre des marchandises récupérés dans un port avec un navire marchand,\n");
    printf("voler puis enterrer une marchandise avec un pirate (2 doublons puis 5 doublons),\n");
    printf("ou utiliser une frégate pour couler un pirate (2 doublons).\n");
    printf("A chaque tour un joueur va :\n");
    printf("Déplacer son marchand.\n");
    printf("S’il arrive sur un port, il va vendre ses marchandises pour 3 doublons et en reprendre automatiquement 3, et peut continuer a bouger s’il lui reste des mouvements.\n");
    printf("Il ne peut pas vendre 2 fois des marchandises dans le même tour.\n");
    printf("Si le marchand a été coulé, il est remis a proximité d’un port et rechargé de 3 marchandises puis commence ses déplacements.\n");
    printf("Déplacer le pirate.\n");
    printf("Un pirate peut pendant son tour soit attaquer un marchand s’il est vide pour gagner 2 doublons,\n");
    printf("soit enterrer sa marchandise s’il en a une pour gagner 5 doublons.\n");
    printf("Il ne peut réaliser ces deux actions le même tour.\n");
    printf("Si le pirate est coulé, le joueur le replace sur une case mer lointaine et peut le déplacer.\n");
    printf("Déplacer la frégate concernée par sa carte.\n");
    printf("La frégate peut attaquer UN pirate situé sur une case adjacente pour gagner 2 doublons.\n");
    printf("Si le pirate a une marchandise, elle est remise dans le stock.\n");
    printf("Petite spécificité : un joueur ne peux déverrouiller qu’une carte développement par tour.\n");
    printf("Bonne partie !\n");
}
