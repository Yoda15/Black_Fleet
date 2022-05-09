#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Declarations_Variables.h"
#include "../Affichage/Plateau.h"

int couleur[2]={CF1,CF2};
int Vente[5][5]={{1,3,2,2,0},{0,2,3,2,1},{2,0,1,3,3},{2,1,0,2,3},{3,2,2,0,2}};

int Choix_Dep(int tab[]){
    /**Choix d'un d�placement**/
    int k;
    do{
    system("cls");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("|                                         Black Fleet/D�placement                                        |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n\n");
    printf("                                            |-----Tirage1-----|\n");
    color(couleur[tab[3]],0);
    printf("                                              1-Fr�gate : %d\n", tab[0]);
    color(15,0);
    printf("                                              2-Pirate : %d\n", tab[1]);
    printf("                                              3-Marchand : %d\n\n", tab[2]);
    printf("                                              4-Fin des d�placements\n");
    printf("Merci de faire votre choix : ");
    scanf("%d", &k);
    if(k<1 || k>4){
        color(4,0);
        printf("\nMerci de choisir une des options propos�es !");
        Sleep(2000);
        color(15,0);
    }
    }while(k<1 || k>4);
    return k;
}

void Erreur(int a){
    /**Permet de Centraliser les erreurs**/
    color(4,0);
    if(a==0){
        printf("\n\nPlus Aucun d�placement disponible");
    }
    else if(a==1){
        printf("\n\nImpossible Capitaine, nous allons nous �chouer/c'est trop dangereux !!!");
    }
    else if(a==1){
        printf("\n\nLes Marchandises sont � livrer dans un autre Port !!!");
    }
    else if(a==4){
        printf("\n\nHOPLA!!!   Pas par ici");
    }
    else if(a==5){
        printf("\n\nHO! Capitaine, nos marins on besoin de repos !!!");
    }
    else if(a==6){
        printf("\nMerci de choisir une des options propos�es !");
    }
    color(15,0);
    Sleep(1000);
}


void Case_Libre(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j, int Position[]){
    /**Action � Effectuer en cas de case libre**/
    if(Position[2]<0 || Position[2]>Larg || Position[3]<0 || Position[3]>Larg){ //V�rification que le plateau n'est pas d�pass�
        Erreur(4);
    }
    else if((P[Position[3]][Position[2]].type==0) || (P[Position[3]][Position[2]].type==2) || (((*type==1)||(*type==2)) && ((P[Position[3]][Position[2]].type==4) || (P[Position[3]][Position[2]].type==5) || (P[Position[3]][Position[2]].type==6) || (P[Position[3]][Position[2]].type==7) || (P[Position[3]][Position[2]].type==8)))){ //V�rification ni C�tes, ni Mer lointaine
        Erreur(1); //V�rification du type de case et des bateaux qui peuvent y acc�der
    }
    else if(*type==3 && P[Position[3]][Position[2]].type==J[j].M.type_marchandise){ //V�rification du type de marchandise avant l'arriv�e dans le port
        Erreur(3);
    }
    else{
        if(*type==1){ //si c'est une fr�gate
            F[tab[3]].coordonee[0]=Position[3];
            F[tab[3]].coordonee[1]=Position[2];
            P[Position[3]][Position[2]].bateau=tab[3]+2;
        }
        else if(*type==2){ //si c'est un pirate
            if(P[Position[3]][Position[2]].type==3 && J[j].P.marchandise==1){ //Si case Tr�sor
                J[j].doublons=J[j].doublons+TRESOR;
                J[j].P.marchandise=0;
                action[1]=1;
            }
            J[j].P.coordonee[0]=Position[3];
            J[j].P.coordonee[1]=Position[2];
            P[Position[3]][Position[2]].bateau=1;
            P[Position[3]][Position[2]].joueur=j;
        }
        else{ //si c'est un marchand
                //En cas de Case Port
            if(P[Position[3]][Position[2]].type==4 && J[j].M.marchandise!=0 && action[2]!=1){
                J[j].doublons=J[j].doublons+J[j].M.marchandise*Vente[PORT_OUTILS][J[j].M.type_marchandise%5];
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=4;
                action[2]=1;
            }
            else if(P[Position[3]][Position[2]].type==5 && J[j].M.marchandise!=0 && action[2]!=1){
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_RIZ][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=5;
                action[2]=1;
            }
            else if(P[Position[3]][Position[2]].type==6 && J[j].M.marchandise!=0 && action[2]!=1){
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_BLE][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=6;
                action[2]=1;
            }
            else if(P[Position[3]][Position[2]].type==7 && J[j].M.marchandise!=0 && action[2]!=1){
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_ERABLE][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=7;
                action[2]=1;
            }
            else if(P[Position[3]][Position[2]].type==8 && J[j].M.marchandise!=0 && action[2]!=1){
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_VIN][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=8;
                action[2]=1;
            }
            else if(action[2]==1){
                Erreur(5);
            }
            if(P[Position[3]][Position[2]].type==1 || action[2]!=1){
                J[j].M.coordonee[0]=Position[3];
                J[j].M.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=0;
                P[Position[3]][Position[2]].joueur=j;
            }
        }
        //Netoyage apr�s passage et -1 d�placement
        P[Position[1]][Position[0]].etat=0;
        P[Position[3]][Position[2]].etat=1;
        tab[*type-1]--;
    }
}

void Verification_Case(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j){
    /**V�rification de la case choisie**/
    int i, fin=1, x,y, Position[4];
    do{
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                         Black Fleet/D�placement                                        |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        Affichage_Plateau(P,J,F);
        i=0;
        while(i!=HAUT && i!=BAS && i!=DROITE && i!=GAUCHE && i!=ECHAP){
        i=getch();
        }
        if(*type==1){ //si c'est une fr�gate
                y=F[tab[3]].coordonee[0], x=F[tab[3]].coordonee[1];
        }
        else if(*type==2){ //Si c'est un pirate
                y=J[j].P.coordonee[0], x=J[j].P.coordonee[1];
        }
        else{ //Sinon c'est un marchand
                y=J[j].M.coordonee[0], x=J[j].M.coordonee[1];
        }
        Position[0]=x;
        Position[1]=y;
        switch(i){
        case HAUT: //Fl�che du Haut
            if(P[y-1][x].etat==0){
                Position[2]=x;
                Position[3]=y-1;
                Case_Libre(type,tab,action,J,P,F,j,Position);
                 fin=0;
            }
            else{
                printf("AH!");
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case BAS: //Fl�che du Bas
            if(P[y+1][x].etat==0){
                Position[2]=x;
                Position[3]=y+1;
                Case_Libre(type,tab,action,J,P,F,j,Position);
                 fin=0;
            }
            else{
                printf("AH!");
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case GAUCHE: //Fl�che de Gauche
            if(P[y][x-1].etat==0){
                Position[2]=x-1;
                Position[3]=y;
                Case_Libre(type,tab,action,J,P,F,j,Position);
                 fin=0;
            }
            else{
                printf("AH!");
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case DROITE: //Fl�che de Droite
            if(P[y][x+1].etat==0){
                Position[2]=x+1;
                Position[3]=y;
                Case_Libre(type,tab,action,J,P,F,j,Position);
                 fin=0;
            }
            else{
                printf("AH!");
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case ECHAP:
            fin=0;
            *type=0;
            break;
        }
    }while(fin!=0);
}

void Deplacements(Joueur J[], S_Case P[][Long], fregate F[], int j, int tab[]){
    /**D�placement et Action de Chaque Joueur**/
    int choix, Action[3]={0,0,0};
    do{
        choix=Choix_Dep(tab);
        switch(choix){
        case 1:
            if (tab[0]!=0){
                while(tab[0]!=0 && choix!=0){
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else{
                Erreur(0);
            }
            break;
        case 2:
            if (tab[1]!=0){
                while(tab[1]!=0 && choix!=0){
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else{
                Erreur(0);
            }
            break;
        case 3:
            if (tab[2]!=0){
                while(tab[2]!=0 && choix!=0){
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else{
                Erreur(0);
            }
            break;
        case 4:
            tab[0]=0;
            tab[1]=0;
            tab[2]=0;
            break;

        }
    }while(tab[0]!=0 || tab[1]!=0 || tab[2]!=0);
}
