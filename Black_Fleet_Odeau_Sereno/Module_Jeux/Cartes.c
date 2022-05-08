#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"

void Achat_Carte(Joueur *J){
    /**Achat de Carte de Développement et de Fin de Partie**/
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




void Cartes_Aleatoire(int tab[]){
    /**Tirage x2 de Cartes Aléatoires de Déplacement**/
    color(4,0);
    printf("\nTirage des Cartes... Merci de Patienter...");
    color(15,0);
    int tab1[CARTES+1], tab2[CARTES+1];
    int k,i;
    int couleur[2]={CF1,CF2};
    srand(time(NULL));
    for(i=0; i<CARTES+1; i++){
        tab1[i]=(rand()%NB_DEP_MAX);
    }
    tab1[3]=tab1[3]%2;
    Sleep(rand()%2000); //Permet d'augmenter les chances d'aléatoires
    for(i=0; i<CARTES+1; i++){
        tab2[i]=(rand()%NB_DEP_MAX);
    }
    tab2[3]=tab2[3]%2;
    //Choix Du Joueur
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                         Black Fleet/Déplacement                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n\n");
    printf("                            |-----Tirage1-----|            |-----Tirage2-----|\n");
    color(couleur[tab1[3]],0);
    printf("                              -Frégate : %d                ", tab1[0]);
    color(couleur[tab2[3]],0);
    printf("   -Frégate : %d\n", tab2[0]);
    color(15,0);
    printf("                              - Pirate : %d                   -Pirate : %d\n", tab1[1], tab2[1]);
    printf("                              - Marchand : %d                 -Marchand : %d\n\n", tab1[2], tab2[2]);
    printf("Merci de faire votre choix (1/2): ");
    scanf("%d", &k);
    if(k!=1 && k!=2){
        color(4,0);
        printf("\nMerci de choisir une des deux options proposées !");
        Sleep(2000);
        color(15,0);
    }
    }while(k!=1 && k!=2);
    switch(k){
    case 1:
        for(i=0; i<CARTES+1; i++){
            tab[i]=tab1[i];
        }
        break;
    case 2:
        for(i=0; i<CARTES+1; i++){
            tab[i]=tab2[i];
        }
        break;
    }
}

