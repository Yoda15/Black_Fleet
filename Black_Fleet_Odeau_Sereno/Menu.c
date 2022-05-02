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
    scanf("%d", i);
    if ((i<1) && (i>3)){
        color(4,0);
        printf("\nMerci de Choisir une option entre 1 et 3 !!!");
        color(15,0);
    }
    }while((i<1) && (i>3));
    return i;
}
