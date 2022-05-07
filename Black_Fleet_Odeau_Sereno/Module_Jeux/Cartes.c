#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"

void Achat_Carte(Joueur *J){
    char choix[1];
    int i=0;
    int C;
    int Prix[6];
    Prix[0]=0, Prix[1]=8, Prix[2]=5, Prix[3]=11, Prix[4]=14, Prix[5]=20;
    do{
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                             Black Fleet/Market                                         |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        printf("    Joueur : ");
        color((*J).couleur,2);
        printf("%s\n", (*J).nom);
        color(15,0);
        printf("Souhaitez-Vous acheter une carte de développement/Fin de Partie ? (O/N) : ");
        scanf("%s", choix);
    }while(((strcmp(choix,"O"))!=0) && (strcmp(choix,"N"))!=0 && (strcmp(choix,"o"))!=0 && (strcmp(choix,"n"))!=0);
    if(strcmp(choix,"O")==0 || (strcmp(choix,"o"))==0){
        do{
        printf("\n\n|-----Magasin-----|\n");
        printf("1-Assurance tous risques (8 doublons)\n");
        printf("2-Code du Pirate (5 doublons)\n");
        printf("3-Toutes voiles dehors (11 doublons)\n");
        printf("4-Potion Magique (14 doublons)\n");
        printf("5-Carte de Fin de Partie (20 doublons)\n");
        printf("0-Annuler l'achat\n");
        printf("Que souhaitez-vous acheter ? : ");
        scanf("%d", &C);
        if(C==0 || C==1 || C==2 || C==3 || C==4 || C==5){
            if(C==0){
                color(4,0);
                printf("\nAnnulation de l'achat...");
                color(15,0);
                Sleep(1000);
                i=1;
            }
            else if(C==5 && ((*J).Pioche.dev[0]==0 || (*J).Pioche.dev[1]==0 || (*J).Pioche.dev[2]==0 || (*J).Pioche.dev[3]==0)){
                color(4,0);
                printf("Merci d'acheter toutes les autres cartes avant !");
                color(15,0);
                Sleep(1000);
            }
            else if((*J).doublons>=Prix[C]){
                i=1;
                if(C==5){
                    (*J).Pioche.Fin_Partie=1;
                }
                else (*J).Pioche.dev[C-1]=1;
                color(4,0);
                printf("\nAchat Effectué !");
                color(15,0);
                (*J).Pioche.dev[C-1]=1;
                (*J).doublons=(*J).doublons-Prix[C];
                Sleep(2000);
            }
            else if((*J).Pioche.dev[C-1]==1){
                color(4,0);
                printf("\nCarte Déjà Acheté...");
                color(15,0);
                Sleep(500);
            }
            else if((*J).doublons<Prix[C]){
                color(4,0);
                printf("\nArgent Insuffisant...");
                color(15,0);
                Sleep(500);
            }
        }
        }while(i==0);
    }
    system("cls");
}



/*
void Carte_Aléatoire(int tab[]){
    printf("ok");
}
*/
