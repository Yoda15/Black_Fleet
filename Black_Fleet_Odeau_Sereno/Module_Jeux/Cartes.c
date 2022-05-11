#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "Message.h"

void Achat_Carte(Joueur *J){
    /**Achat de Carte de Développement et de Fin de Partie**/
    char choix[1];
    int i=0;
    int C;
    int Prix[6];
    Prix[0]=0, Prix[1]=8, Prix[2]=5, Prix[3]=11, Prix[4]=14, Prix[5]=20; //Prix de Vente
    do{
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                             Black Fleet/Market                                         |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        printf("        Joueur : ");
        color((*J).couleur,BLEU);
        printf("%s\n",(*J).nom);
        color(BLANC,NOIR);
        printf("        Doublons : %d\n\n",(*J).doublons);
        printf("Souhaitez-Vous acheter une carte de développement/Fin de Partie ? (O/N) : ");
        scanf("%s", choix);
    }while(((strcmp(choix,"O"))!=0) && (strcmp(choix,"N"))!=0 && (strcmp(choix,"o"))!=0 && (strcmp(choix,"n"))!=0); //Vérification de l'entrée
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
        if(C==0 || C==1 || C==2 || C==3 || C==4 || C==5){ //Achats Cartes si selections
            if(C==0){ //Annuler
                Messages(12);
                i=1;
            }
            else if(C==5 && ((*J).Pioche.dev[0]==0 || (*J).Pioche.dev[1]==0 || (*J).Pioche.dev[2]==0 || (*J).Pioche.dev[3]==0)){ //Vérification d'achats de toutes les autres cartes avant la final
                Messages(13);
            }
            else if((*J).Pioche.dev[C-1]==1){ //Carte Déjà acheté
                Messages(14);
            }
            else if((*J).doublons>=Prix[C]){ //Carte Acheté(si prix< nb doublons)
                i=1;
                if(C==5){
                    (*J).Pioche.Fin_Partie=1;
                }
                else (*J).Pioche.dev[C-1]=1;
                Messages(15);
                (*J).Pioche.dev[C-1]=1;
                (*J).doublons=(*J).doublons-Prix[C];
                i=1;
            }
            else if((*J).doublons<Prix[C]){ //Manque d'argents
                Messages(16);
            }
        }
        }while(i==0);
    }
    system("cls");
}

void Tirage_Choisi(int tab[], Joueur J, int tabx[]){
    /**Transfert Choix_Tirage->Carte déplacements**/
    int i;
    for(i=0; i<CARTES+1; i++){ //Selon le Tirage Choisi
        tab[i]=tabx[i];
    }
    if(J.Pioche.dev[2]==1){ //Si carte dev 3 débloqué, alors +1 déplacements
        for(i=0; i<CARTES; i++){
            tab[i]++;
        }
    }
}

void Cartes_Aleatoire(int tab[], Joueur J){
    /**Tirage x2 de Cartes Aléatoires de Déplacement**/
    color(ROUGE,NOIR);
    printf("\n\n                Tirage des Cartes... Merci de Patienter...");
    color(BLANC,NOIR);
    int tab1[CARTES+1], tab2[CARTES+1], tab3[CARTES+1];
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
    if(J.Pioche.dev[3]==1){ //Si carte dev 4 débloqué, alors créer une nouvelle carte
        Sleep(rand()%2000);
        for(i=0; i<CARTES+1; i++){
            tab3[i]=(rand()%NB_DEP_MAX);
        }
        tab3[3]=tab3[3]%2;
    }
    //Choix Du Joueur
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                         Black Fleet/Déplacement                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n\n");
    printf("        Joueur : ");
    color(J.couleur,BLEU);
    printf("%s\n",J.nom);
    color(BLANC,NOIR);
    printf("        Doublons : %d\n\n",J.doublons);
    printf("                            |-----Tirage1-----|            |-----Tirage2-----|\n");
    color(couleur[tab1[3]],0);
    printf("                              -Frégate : %d                ", tab1[0]);
    color(couleur[tab2[3]],0);
    printf("   -Frégate : %d\n", tab2[0]);
    color(15,0);
    printf("                              - Pirate : %d                   -Pirate : %d\n", tab1[1], tab2[1]);
    printf("                              - Marchand : %d                 -Marchand : %d\n\n", tab1[2], tab2[2]);
    if(J.Pioche.dev[3]==1){ //Si carte dev 4 débloqué, alors Afficher la nouvelle Carte
        printf("                                            |-----Tirage3-----|\n");
        color(couleur[tab3[3]],0);
        printf("                                              -Frégate : %d\n", tab1[0]);
        color(15,0);
        printf("                                              - Pirate : %d\n", tab3[1]);
        printf("                                              - Marchand : %d\n\n", tab3[2]);
    }
    printf("Merci de faire votre choix (1/2[+3]): ");
    scanf("%d", &k);
    if(((J.Pioche.dev[3]==0) && (k!=1 && k!=2)) || ((J.Pioche.dev[3]==1) && (k<1 && k>3))){
        Messages(6);
    }
    }while(((J.Pioche.dev[3]==0) && (k!=1 && k!=2)) || ((J.Pioche.dev[3]==1) && (k<1 && k>3)));
    switch(k){ //Transfert Choix_Tirage->Carte déplacements
    case 1: //si tirage 1 choisi
        Tirage_Choisi(tab,J,tab1);
        break;
    case 2: //si tirage 2 choisi
        Tirage_Choisi(tab,J,tab2);
        break;
    case 3: //si tirage 3 choisi
        Tirage_Choisi(tab,J,tab3);
        break;
    }
}
