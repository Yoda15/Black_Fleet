#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Declarations_Variables.h"
#include "../Affichage/Plateau.h"

int couleur[2]= {CF1,CF2};
int Vente[5][5]= {{1,3,2,2,0},{0,2,3,2,1},{2,0,1,3,3},{2,1,0,2,3},{3,2,2,0,2}};

int Choix_Dep(int tab[])
{
    /**Choix d'un d�placement**/
    int k;
    do
    {
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
        if(k<1 || k>4)
        {
            color(4,0);
            printf("\nMerci de choisir une des options propos�es !");
            Sleep(2000);
            color(15,0);
        }
    }
    while(k<1 || k>4);
    return k;
}

void Erreur(int a)
{
    /**Permet de Centraliser les erreurs**/
    color(4,0);
    switch(a)
    {
    case 0:
        printf("\n\nPlus Aucun d�placement disponible");
        break;
    case 1:
        printf("\n\nImpossible Capitaine, nous allons nous �chouer/c'est trop dangereux !!!");
        break;
    case 2:
        printf("\nEsp�ce de Marin d'eau douce, tu veux couler ton navire !!!");
        break;
    case 3:
        printf("\n\nLes Marchandises sont � livrer dans un autre Port !!!");
        break;
    case 4:
        printf("\n\nHOPLA!!!   Pas par ici");
        break;
    case 5:
        printf("\n\nHO! Capitaine, nos marins on besoin de repos !!!");
        break;
    case 6:
        printf("\nMerci de choisir une des options propos�es !");
        break;
    case 7:
        printf("Morbleu !, nous ne sommes pas des pitrates !!!");
        break;
    case 8:
        printf("Mousaillon, objet volumineux droit devant, changement de cap � effectuer !");
        break;
    case 9:
        printf("Branle-bas de combat !");
        break;
    case 10:
        printf("Vous �tes saoule capitaine, il n'y a plus de place !");
        break;
    case 11:
        printf("Pas de quartier !");
        break;
    }
    color(15,0);
    Sleep(1000);
}

void Mr_Propre(int *type, int tab[], S_Case P[][Long], int Position[], int j, int action[], Joueur J[]){
    //Netoyage apr�s passage et -1 d�placement
    P[Position[1]][Position[0]].etat=0;
    P[Position[3]][Position[2]].etat=1;
    P[Position[3]][Position[2]].joueur=j;
    J[j].M.coordonee[0]=Position[3];
    J[j].M.coordonee[1]=Position[2];
    tab[*type-1]--;
}

void Case_Libre(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j, int Position[])
{
    /**Action � Effectuer en cas de case libre**/
    if(Position[2]<0 || Position[2]>Larg || Position[3]<0 || Position[3]>Long)  //V�rification que le plateau n'est pas d�pass�
    {
        Erreur(4);
    }
    else if((P[Position[3]][Position[2]].type==0) || (P[Position[3]][Position[2]].type==2) || (((*type==1)||(*type==2)) && ((P[Position[3]][Position[2]].type==4) || (P[Position[3]][Position[2]].type==5) || (P[Position[3]][Position[2]].type==6) || (P[Position[3]][Position[2]].type==7) || (P[Position[3]][Position[2]].type==8))))  //V�rification ni C�tes, ni Mer lointaine
    {
        Erreur(1); //V�rification du type de case et des bateaux qui peuvent y acc�der
    }
    else if(*type==3 && P[Position[3]][Position[2]].type==J[j].M.type_marchandise)  //V�rification du type de marchandise avant l'arriv�e dans le port
    {
        Erreur(3);
    }
    else
    {
        if(*type==1)  //si c'est une fr�gate
        {
            F[tab[3]].coordonee[0]=Position[3];
            F[tab[3]].coordonee[1]=Position[2];
            P[Position[3]][Position[2]].bateau=tab[3]+2;
            P[Position[1]][Position[0]].etat=0;
            P[Position[3]][Position[2]].etat=1;
            P[Position[3]][Position[2]].joueur=j;
            tab[*type-1]--;
        }
        else if(*type==2)  //si c'est un pirate
        {
            if(P[Position[3]][Position[2]].etat==1 && action[1]!=0){
                Erreur(5);
            }
            else if(P[Position[3]][Position[2]].type==3 && J[j].P.marchandise==1 && action[1]!=0)  //Si case Tr�sor
            {
                J[j].doublons=J[j].doublons+TRESOR;
                J[j].P.marchandise=0;
                action[1]=1;
                J[j].P.coordonee[0]=Position[3];
                J[j].P.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=1;
                P[Position[3]][Position[2]].joueur=j;
                Mr_Propre(type, tab, P, Position,j,action,J);
            }
            else{
                J[j].P.coordonee[0]=Position[3];
                J[j].P.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=1;
                P[Position[3]][Position[2]].joueur=j;
                Mr_Propre(type, tab, P, Position,j,action,J);
            }
        }
        else  //si c'est un marchand
        {
            //En cas de Case Port
            if(P[Position[3]][Position[2]].type==4 && J[j].M.marchandise!=0 && action[2]!=1)
            {
                J[j].doublons=J[j].doublons+J[j].M.marchandise*Vente[PORT_OUTILS][J[j].M.type_marchandise%5];
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=4;
                action[2]=1;
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
            }
            else if(P[Position[3]][Position[2]].type==5 && J[j].M.marchandise!=0 && action[2]!=1)
            {
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_RIZ][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=5;
                action[2]=1;
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
            }
            else if(P[Position[3]][Position[2]].type==6 && J[j].M.marchandise!=0 && action[2]!=1)
            {
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_BLE][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=6;
                action[2]=1;
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
            }
            else if(P[Position[3]][Position[2]].type==7 && J[j].M.marchandise!=0 && action[2]!=1)
            {
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_ERABLE][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=7;
                action[2]=1;
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
            }
            else if(P[Position[3]][Position[2]].type==8 && J[j].M.marchandise!=0 && action[2]!=1)
            {
                J[j].doublons=J[j].doublons+((J[j].M.marchandise)*Vente[PORT_VIN][J[j].M.type_marchandise%5]);
                J[j].M.marchandise=3;
                J[j].M.type_marchandise=8;
                action[2]=1;
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
            }
            else if(P[Position[3]][Position[2]].type==1 || action[2]!=1)
            {
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;

            }
            else if(action[2]==1)
            {
                Erreur(5);
            }
        }
    }
}

void Case_Prise(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j, int Position[])
{
    /**Action � Effectuer en cas de case non libre**/
    if(Position[2]<0 || Position[2]>Larg || Position[3]<0 || Position[3]>Long)  //V�rification que le plateau n'est pas d�pass�
    {
        Erreur(4);
    }
    else if((P[Position[3]][Position[2]].type==0) || (P[Position[3]][Position[2]].type==2) || (((*type==1)||(*type==2)) && ((P[Position[3]][Position[2]].type==4) || (P[Position[3]][Position[2]].type==5) || (P[Position[3]][Position[2]].type==6) || (P[Position[3]][Position[2]].type==7) || (P[Position[3]][Position[2]].type==8))))  //V�rification ni C�tes, ni Mer lointaine
    {
        Erreur(1); //V�rification du type de case et des bateaux qui peuvent y acc�der
    }
    else if(*type==3 && P[Position[3]][Position[2]].type==J[j].M.type_marchandise)  //V�rification du type de marchandise avant l'arriv�e dans le port
    {
        Erreur(3);
    }
    else if(action[*type-1]==1 && (*type==1 || *type==2)){
        Erreur(5);
    }
    else
    {
        if(*type==1)  //si c'est une fr�gate
        {
            if(P[Position[3]][Position[2]].bateau==1 && P[Position[3]][Position[2]].joueur !=j) //Pirates ne nous appartenant pas
            {
                Erreur(9);
                P[Position[3]][Position[2]].etat=0;
                J[P[Position[3]][Position[2]].joueur].P.statut=0, J[P[Position[3]][Position[2]].joueur].P.marchandise=0;
                J[j].doublons=J[j].doublons+TOUCHE_COULE;
                action[*type-1]=1;
            }
            else if(P[Position[3]][Position[2]].joueur ==j || P[Position[3]][Position[2]].joueur==((tab[3]+1)%2))
            {
                Erreur(2);
            }
            else if(P[Position[3]][Position[2]].bateau==0)
            {
                Erreur(7);
            }
        }
        else if(*type==2)  //si c'est un pirate
        {
            if(P[Position[3]][Position[2]].bateau==0 && P[Position[3]][Position[2]].joueur !=j)
            {
                if(J[j].P.marchandise==1)
                {
                    Erreur(10);
                }
                else if(J[P[Position[3]][Position[2]].joueur].M.marchandise==1)
                {
                    Erreur(11);
                    P[Position[3]][Position[2]].etat=0;
                    J[P[Position[3]][Position[2]].joueur].M.statut=0, J[P[Position[3]][Position[2]].joueur].M.marchandise=0;
                    J[j].P.marchandise=1;
                    J[j].doublons=J[j].doublons+MARCHAND_COULE;
                    action[*type-1]=1;
                }
                else
                {
                    Erreur(11);
                    J[P[Position[3]][Position[2]].joueur].M.marchandise--;
                    J[j].P.marchandise++;
                    action[*type-1]=1;
                }
            }
            else if(P[Position[3]][Position[2]].joueur ==j || P[Position[3]][Position[2]].joueur==(tab[3]+1)%2)
            {
                Erreur(2);
            }
            else if(P[Position[3]][Position[2]].bateau==0 || P[Position[3]][Position[2]].bateau==1)
            {
                Erreur(7);
            }
        }
        else  //si c'est un marchand
        {
            Erreur(8);
        }
        //Netoyage apr�s passage et -1 d�placement
    }
}

void Verification_Case(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j)
{
    /**V�rification de la case choisie**/
    int i, fin=1, x,y, Position[4];
    do
    {
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                         Black Fleet/D�placement                                        |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        Affichage_Plateau(P,J,F);
        i=0;
        while(i!=HAUT && i!=BAS && i!=DROITE && i!=GAUCHE && i!=ECHAP)
        {
            i=getch();
        }
        if(*type==1)  //si c'est une fr�gate
        {
            y=F[tab[3]].coordonee[0], x=F[tab[3]].coordonee[1];
        }
        else if(*type==2)  //Si c'est un pirate
        {
            y=J[j].P.coordonee[0], x=J[j].P.coordonee[1];
        }
        else  //Sinon c'est un marchand
        {
            y=J[j].M.coordonee[0], x=J[j].M.coordonee[1];
        }
        Position[0]=x;
        Position[1]=y;
        switch(i)
        {
        case HAUT: //Fl�che du Haut
            Position[2]=x;
            Position[3]=y-1;
            if(P[y-1][x].etat==0)
            {
                Case_Libre(type,tab,action,J,P,F,j,Position);
            }
            else
            {
                Case_Prise(type,tab,action,J,P,F,j,Position);
            }
            fin=0;
            break;
        case BAS: //Fl�che du Bas
            Position[2]=x;
            Position[3]=y+1;
            if(P[y+1][x].etat==0)
            {
                Case_Libre(type,tab,action,J,P,F,j,Position);
            }
            else
            {
                Case_Prise(type,tab,action,J,P,F,j,Position);
            }
            fin=0;
            break;
        case GAUCHE: //Fl�che de Gauche
            Position[2]=x-1;
            Position[3]=y;
            if(P[y][x-1].etat==0)
            {
                Case_Libre(type,tab,action,J,P,F,j,Position);
            }
            else
            {
                Case_Prise(type,tab,action,J,P,F,j,Position);
            }
            fin=0;
            break;
        case DROITE: //Fl�che de Droite
            Position[2]=x+1;
            Position[3]=y;
            if(P[y][x+1].etat==0)
            {
                Case_Libre(type,tab,action,J,P,F,j,Position);
            }
            else
            {
                Case_Prise(type,tab,action,J,P,F,j,Position);
            }
            fin=0;
            break;
        case ECHAP:
            fin=0;
            *type=0;
            break;
        }
    }
    while(fin!=0);
}

void Deplacements(Joueur J[], S_Case P[][Long], fregate F[], int j, int tab[])
{
    /**D�placement et Action de Chaque Joueur**/
    int choix, Action[3]= {0,0,0};
    do
    {
        choix=Choix_Dep(tab);
        switch(choix)
        {
        case 1:
            if (tab[0]!=0)
            {
                while((tab[0]!=0 || Action[0]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else
            {
                Erreur(0);
            }
            break;
        case 2:
            if (tab[1]!=0)
            {
                while((tab[1]!=0 || Action[1]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else
            {
                Erreur(0);
            }
            break;
        case 3:
            if (tab[2]!=0)
            {
                while((tab[2]!=0 || Action[2]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                }
            }
            else
            {
                Erreur(0);
            }
            break;
        case 4:
            tab[0]=0;
            tab[1]=0;
            tab[2]=0;
            break;

        }
    }
    while(tab[0]!=0 || tab[1]!=0 || tab[2]!=0);
}

