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
    printf("|                                               2-> R�gles                                               |\n");
    printf("|                                               3-> Cr�dits                                              |\n");
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
    printf("d�verrouiller 4 cartes d�veloppement puis une carte victoire pour gagner la partie.\n");
    printf("Chaque carte d�veloppement coute un certain nombre de doublons (5, 8, 11, 14) et la carte victoire coute 10 doublons.\n");
    printf("En cas d��galit� (si 2 joueurs d�bloquent la carte victoire sur le m�me tour),\n");
    printf("celui qui a le plus de doublons a la fin du tour final gagne.\n");
    printf("Pour gagner des doublons il y a trois possibilit�s :\n");
    printf("vendre des marchandises r�cup�r�s dans un port avec un navire marchand,\n");
    printf("voler puis enterrer une marchandise avec un pirate (2 doublons puis 5 doublons),\n");
    printf("ou utiliser une fr�gate pour couler un pirate (2 doublons).\n");
    printf("A chaque tour un joueur va :\n");
    printf("D�placer son marchand.\n");
    printf("S�il arrive sur un port, il va vendre ses marchandises pour 3 doublons et en reprendre automatiquement 3, et peut continuer a bouger s�il lui reste des mouvements.\n");
    printf("Il ne peut pas vendre 2 fois des marchandises dans le m�me tour.\n");
    printf("Si le marchand a �t� coul�, il est remis a proximit� d�un port et recharg� de 3 marchandises puis commence ses d�placements.\n");
    printf("D�placer le pirate.\n");
    printf("Un pirate peut pendant son tour soit attaquer un marchand s�il est vide pour gagner 2 doublons,\n");
    printf("soit enterrer sa marchandise s�il en a une pour gagner 5 doublons.\n");
    printf("Il ne peut r�aliser ces deux actions le m�me tour.\n");
    printf("Si le pirate est coul�, le joueur le replace sur une case mer lointaine et peut le d�placer.\n");
    printf("D�placer la fr�gate concern�e par sa carte.\n");
    printf("La fr�gate peut attaquer UN pirate situ� sur une case adjacente pour gagner 2 doublons.\n");
    printf("Si le pirate a une marchandise, elle est remise dans le stock.\n");
    printf("Petite sp�cificit� : un joueur ne peux d�verrouiller qu�une carte d�veloppement par tour.\n");
    printf("Bonne partie !\n");
}
