#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"

void Achat_Carte(Joueur J){
    char choix[1];
    do{
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                             Black Fleet/Market                                         |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        printf("Souhaitez-Vous acheter une carte de développement/Fin de Partie ? (O/N) : ");
        scanf("%s", choix);
    }while(((strcmp(choix,"O"))!=0) && (strcmp(choix,"N"))!=0 && (strcmp(choix,"o"))!=0 && (strcmp(choix,"n"))!=0);
    if(strcmp(choix,"O")==0 || (strcmp(choix,"o"))==0){
        printf("\n\n|-----Magasin-----|\n");
        printf("1-");
        printf("2-");
        printf("3-");
        printf("4-");
        printf("0-Annuler l'achat");
    }
}
