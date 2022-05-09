#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Declarations_Variables.h"
#include "../Affichage/Plateau.h"

int couleur[2]={CF1,CF2};

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



void Verification_Case(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j){
    /**V�rification de la case choisie**/
    int i, fin=1, x,y;
    do{
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                         Black Fleet/D�placement                                        |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        Affichage_Plateau(P,J,F);
        i=0;
        while(i!=HAUT && i!=BAS && i!=DROITE && i!=GAUCHE){
        i=getch();
        }
        if(type==1){ //si c'est une fr�gate
                int x=F[tab[3]].coordonee[0], y=F[tab[3]].coordonee[1];
        }
        else if(type==2){ //Si c'est un pirate
                x=J[j].P.coordonee[0], y=J[j].P.coordonee[1];
        }
        else{ //Si c'est un marchand
                x=F[tab[3]].coordonee[0], y=F[tab[3]].coordonee[1];
        }
        printf("\n%d    %d",J[j].M.coordonee[0],J[j].M.coordonee[1]);
        Sleep(50);
        switch(i){
        case HAUT: //Fl�che du Haut
            if(P[x][y+1].etat==0){
                if(P[x][y+1].type==0 || P[x][y+1].type==2){ //V�rification ni C�tes, ni Mer lointaine
                    color(4,0);
                    printf("\n\nImpossible Capitaine, nous allons nous �chouer !!!");
                    printf("%d    %d",F[tab[3]].coordonee[0],y=F[tab[3]].coordonee[1]);
                    color(15,0);
                    Sleep(2000);
                }
                else{
                    if(*type==1){ //si c'est une fr�gate
                        F[tab[3]].coordonee[1]=y+1;
                    }
                    else if(*type==2){
                        J[j].P.coordonee[1]=y+1;
                    }
                    else{
                        J[j].M.coordonee[1]=y+1;
                    }
                    P[x][y].etat=0;
                    P[x][y+1].etat=1;
                    tab[*type-1]--;
                    fin=0;
                    printf("\n%d    %d",F[tab[3]].coordonee[0],F[tab[3]].coordonee[1]);
                    Sleep(2000);
                }
            }
            else{
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case BAS: //Fl�che du Bas
            if(P[x][y-1].etat==0){
                if(P[x][y-1].type==0 || P[x][y-1].type==2){
                    color(4,0);
                    printf("\n\nImpossible Capitaine, nous allons nous �chouer !!!");
                    color(15,0);
                }
                else{
                    if(type==1){ //si c'est une fr�gate
                        F[tab[3]].coordonee[0]=y-1;
                    }
                    else if(type==2){
                        J[j].P.coordonee[0]=y-1;
                    }
                    else{
                        J[j].M.coordonee[0]=y-1;
                    }
                    P[x][y].etat=0;
                    P[x][y-1].etat=0;
                }
            }
            else{
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case GAUCHE: //Fl�che de Gauche
            if(P[x][y+1].etat==0){
                if(P[x][y+1].type==0 || P[x][y-1].type==2){
                    color(4,0);
                    printf("\n\nImpossible Capitaine, nous allons nous �chouer !!!");
                    color(15,0);
                }
                else{
                    if(type==1){ //si c'est une fr�gate
                        F[tab[3]].coordonee[0]=y+1;
                    }
                    else if(type==2){
                        J[j].P.coordonee[0]=y+1;
                    }
                    else{
                        J[j].M.coordonee[0]=y+1;
                    }
                    P[x][y].etat=0;
                    P[x][y+1].etat=0;
                }
            }
            else{
                //V�rifier Type Bateau
                //Si pirate �nemie tuer, puis d�placer, Action+1
                //Si bateau alli� v�rifier nombre d�placement
                //Sinon D�placement Impossible
            }
            break;
        case DROITE: //Fl�che de Droite
            if(P[x][y+1].etat==0){
                if(P[x][y+1].type==0 || P[x][y-1].type==2){
                    color(4,0);
                    printf("\n\nImpossible Capitaine, nous allons nous �chouer !!!");
                    color(15,0);
                }
                else{
                    if(type==1){ //si c'est une fr�gate
                        F[tab[3]].coordonee[0]=y+1;
                    }
                    else if(type==2){
                        J[j].P.coordonee[0]=y+1;
                    }
                    else{
                        J[j].M.coordonee[0]=y+1;
                    }
                    P[x][y].etat=0;
                    P[x][y+1].etat=0;
                }
            }
            else{
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
                color(4,0);
                printf("\n\nPlus Aucun d�placement possible");
                color(15,0);
            }
            break;
        case 2:
            if (tab[1]!=0){
                Verification_Case(choix,tab,Action,J,P,F,j);
            }
            else{
                color(4,0);
                printf("\n\nPlus Aucun d�placement possible");
                color(15,0);
            }
            break;
        case 3:
            if (tab[2]!=0){
                Verification_Case(choix,tab,Action,J,P,F,j);
            }
            else{
                color(4,0);
                printf("\n\nPlus Aucun d�placement possible");
                color(15,0);
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
