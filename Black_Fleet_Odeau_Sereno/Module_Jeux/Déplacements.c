#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Declarations_Variables.h"

int couleur[2]={CF1,CF2};

int Choix_Dep(int tab[]){
    /**Choix d'un déplacement**/
    int k;
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                         Black Fleet/Déplacement                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n\n");
    printf("                                            |-----Tirage1-----|\n");
    color(couleur[tab[3]],0);
    printf("                                              1-Frégate : %d", tab[0]);
    color(15,0);
    printf("                                              2-Pirate : %d", tab[1]);
    printf("                                              3-Marchand : %d\n\n", tab[2]);
    printf("                                              4-Fin des déplacements");
    printf("Merci de faire votre choix (1/2): ");
    scanf("%d", &k);
    if(k!=1 && k!=2){
        color(4,0);
        printf("\nMerci de choisir une des options proposées !");
        Sleep(2000);
        color(15,0);
    }
    }while(k<0 || k>4);
    return k;
}

void Deplacements(Joueur J[], S_Case P[][Long], int j, int tab[]){
    /**Déplacement et Action de Chaque Joueur**/
    int choix;
    while(tab[0]!=0 && tab[1]!=0 && tab[2]!=0){
        choix=Choix_Dep(tab);
        //switch(choix){
        //case 1:
        //case 2:
        //case 3:
        //case 4:

        //}
    }
}
