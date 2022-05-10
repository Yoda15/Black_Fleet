#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Declarations_Variables.h"
#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Affichage/Plateau.h"
#include "Déplacements.h"

int etat(S_Case P[][Long], int i, int k){
    /**Vérifier place plateau**/
    if(i==0){
        if(k==1){
           if(P[0][6].etat==0 || P[0][7].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==2){
            if(P[0][2].etat==0 || P[0][3].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==3){
            if(P[9][0].etat==0 || P[10][0].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==4){
            if(P[11][6].etat==0 || P[11][7].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==5){
            if(P[5][13].etat==0 || P[6][13].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
    }
    else{
        if(k==1){
           if(P[4][0].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==2){
            if(P[5][0].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==3){
            if(P[1][13].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
        else if(k==4){
            if(P[10][13].etat==0){
            return 1;
           }
           else {
            return 0;
           }
        }
    }
}

void Position_Marchand(Joueur *J, S_Case P[][Long], int tab[]){
    if(P[tab[0]][tab[1]].etat==0){ //Si première case libre
        (*J).M.coordonee[0]=tab[0];
        (*J).M.coordonee[1]=tab[1];
        P[tab[0]][tab[1]].etat=1;
        P[tab[0]][tab[1]].bateau=0;
        P[tab[0]][tab[1]].joueur=(*J).nb;
    }
        else{ //Sinon seconde case
        (*J).M.coordonee[0]=tab[2];
        (*J).M.coordonee[1]=tab[3];
        P[tab[2]][tab[3]].etat=1;
        P[tab[2]][tab[3]].bateau=0;
        P[tab[2]][tab[3]].joueur=(*J).nb;
    }
}

void Position_Pirate(Joueur *J, S_Case P[][Long], int tab[]){
    (*J).P.coordonee[0]=tab[0];
    (*J).P.coordonee[1]=tab[1];
    P[tab[0]][tab[1]].etat=1;
    P[tab[0]][tab[1]].bateau=1;
    P[tab[0]][tab[1]].joueur=(*J).nb;
}

void Affichage(Joueur *J, S_Case P[][Long], fregate F[], int i){
    int k, tab[4];
    char name[7];;
    if(i==0){
        name[0]='M';
        name[1]='A';
        name[2]='R';
        name[3]='C';
        name[4]='H';
        name[5]='A';
        name[6]='N';
        name[7]='D';
    }
    else if(i==1){
        name[0]='P';
        name[1]='I';
        name[2]='R';
        name[3]='A';
        name[4]='T';
        name[5]='E';
        name[6]='S';
        name[7]=' ';
    }
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                         Black Fleet/Déplacement                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n\n");
    printf("                                            |--Port_de_Depart--|\n");
    printf("                                            |--de %s--|\n", name);
    color((*J).couleur,CF1);
    printf("           Joueur : %s\n", (*J).nom);
    color(BLANC,NOIR);
    if(i==0){
        printf("                                              1-Port OUTILS\n");
        printf("                                              2-Port RIZ\n");
        printf("                                              3-Port BLE\n");
        printf("                                              4-Port ERABLE\n");
        printf("                                              5-Port VIN\n");
    }
    else if(i==1){
        printf("                                              1-Mer Lointaine Gauche Haut\n");
        printf("                                              2-Mer Lointaine Gauche Bas\n");
        printf("                                              3-Mer Lointaine Droite Haut\n");
        printf("                                              4-Mer Lointaine Droite Bas\n");
    }
    printf("Merci de faire votre choix : ");
    scanf("%d", &k);
    if(i==0){
        if(k<1 || k>5){
            Erreur(6);
    }
    else{
        if(k<1 || k>4){
            Erreur(6);
        }
    }
    }
    if(etat(P,i,k)==0){
        color(ROUGE,NOIR);
        printf("\nPlus De Place... !");
        Sleep(2000);
        color(BLANC,NOIR);
    }
    }while(((i==0) && (k<1 || k>5)) || ((i==1) && (k<1 || k>4)) || etat(P,i,k)==0);
    if(i==0){
        (*J).M.marchandise=3;
        (*J).M.statut=1;
        switch(k){
        case 1:
            tab[0]=0, tab[1]=6, tab[2]=0, tab[3]=7;
            Position_Marchand(J,P,tab);
            (*J).M.type_marchandise=4;
            break;
        case 2:
            tab[0]=0, tab[1]=2, tab[2]=0, tab[3]=3;
            Position_Marchand(J,P,tab);
            (*J).M.type_marchandise=5;
            break;
        case 3:
            tab[0]=9, tab[1]=0, tab[2]=10, tab[3]=0;
            Position_Marchand(J,P,tab);
            (*J).M.type_marchandise=6;
            break;
        case 4:
            tab[0]=11, tab[1]=6, tab[2]=11, tab[3]=7;
            Position_Marchand(J,P,tab);
            (*J).M.type_marchandise=7;
            break;
        case 5:
            tab[0]=5, tab[1]=13, tab[2]=6, tab[3]=13;
            Position_Marchand(J,P,tab);
            (*J).M.type_marchandise=8;
            break;
    }
    (*J).M.statut=1;
    }
    else if(i==1){
        switch(k){
        case 1:
            tab[0]=4, tab[1]=0;
            Position_Pirate(J, P, tab);
            break;
        case 2:
            tab[0]=5, tab[1]=0;
            Position_Pirate(J, P, tab);
            break;
        case 3:
            tab[0]=1, tab[1]=13;
            Position_Pirate(J, P, tab);
            break;
        case 4:
            tab[0]=10, tab[1]=13;
            Position_Pirate(J, P, tab);
            break;
    }
    (*J).P.statut=1;
    }
}

void Placement_Bateau(Joueur *J, S_Case P[][Long], fregate F[]){
    /**Initialisation et Placements des bateaux joueurs**/
    if((*J).M.statut==0){
        int i=0;
        Affichage(J,P,F,i);
    }
    if((*J).P.statut==0){
        int i=1;
        Affichage(J,P,F,i);
    }
}
