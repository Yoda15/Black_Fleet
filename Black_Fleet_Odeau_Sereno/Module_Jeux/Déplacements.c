#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"
#include "../Declarations_Variables.h"
#include "../Affichage/Plateau.h"
#include "Message.h"

int couleur[2]= {CF1,CF2};
int Vente[5][5]= {{1,3,2,2,0},{0,2,3,2,1},{2,0,1,3,3},{2,1,0,2,3},{3,2,2,0,2}};
int Type_March[5]= {PORT_OUTILS,PORT_RIZ,PORT_BLE,PORT_ERABLE,PORT_VIN};

int Choix_Dep(int tab[],Joueur J)
{
    /**Choix d'un déplacement**/
    int k;
    do
    {
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                         Black Fleet/Déplacement                                        |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n\n");
        printf("        Joueur : ");
        color(J.couleur,BLEU);
        printf("%s\n",J.nom);
        color(BLANC,NOIR);
        printf("        Doublons : %d\n\n",J.doublons);
        printf("                                            |-----Tirage1-----|\n");
        color(couleur[tab[3]],0);
        printf("                                              1-Frégate : %d\n", tab[0]);
        color(15,0);
        printf("                                              2-Pirate : %d\n", tab[1]);
        printf("                                              3-Marchand : %d\n\n", tab[2]);
        printf("                                              4-Fin des déplacements\n");
        printf("Merci de faire votre choix : ");
        scanf("%d", &k);
        if(k<1 || k>4)
        {
            color(4,0);
            printf("\nMerci de choisir une des options proposées !");
            Sleep(2000);
            color(15,0);
        }
    }
    while(k<1 || k>4);
    return k;
}

void Mr_Propre(int *type, int tab[], S_Case P[][Long], int Position[], int j, int action[], Joueur J[])
{
    //Netoyage après passage et -1 déplacement
    P[Position[1]][Position[0]].etat=0;
    P[Position[3]][Position[2]].etat=1;
    P[Position[3]][Position[2]].joueur=j;
    tab[*type-1]--;
}

void Vente_Marchandises(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], int j, int Position[], int march)
{
    /**Permet de vendre les marchandises de la frégates**/
    J[j].doublons=J[j].doublons+J[j].M.marchandise*Vente[Type_March[march-4]][J[j].M.type_marchandise%5];
    if(J[j].Pioche.dev[0]==1)  //Si carte dev 1 débloqué, +2 doublons par marchandises qui manquent
    {
        J[j].doublons=J[j].doublons+((3-J[j].M.marchandise)*ASSURANCE_PERTE);
    }
    J[j].M.marchandise=3;
    J[j].M.type_marchandise=march;
    action[*type-1]=1;
    Mr_Propre(type, tab, P, Position,j,action,J);
    P[Position[3]][Position[2]].bateau=0;
    J[j].M.coordonee[0]=Position[3];
    J[j].M.coordonee[1]=Position[2];
}

void Case_Libre(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j, int Position[])
{
    /**Action à Effectuer en cas de case libre**/
    if(Position[2]<0 || Position[2]>Long-1 || Position[3]<0 || Position[3]>Larg-1)  //Vérification que le plateau n'est pas dépassé
    {
        Messages(4);
    }
    else if((P[Position[3]][Position[2]].type==0) || (P[Position[3]][Position[2]].type==2) || (((*type==1)||(*type==2 && (J[j].Pioche.dev[1]==0 || J[j].P.marchandise==0))) && ((P[Position[3]][Position[2]].type==4) || (P[Position[3]][Position[2]].type==5) || (P[Position[3]][Position[2]].type==6) || (P[Position[3]][Position[2]].type==7) || (P[Position[3]][Position[2]].type==8))))  //Vérification ni Côtes, ni Mer lointaine
    {
        Messages(1); //Vérification du type de case et des bateaux qui peuvent y accéder
    }
    else if(*type==3 && P[Position[3]][Position[2]].type==J[j].M.type_marchandise)  //Vérification du type de marchandise avant l'arrivée dans le port
    {
        Messages(3);
    }
    else
    {
        if(*type==1)  //si c'est une frégate
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
            if((P[Position[3]][Position[2]].type>=4 || P[Position[3]][Position[2]].type==3) && action[*type-1]!=0)
            {
                Messages(5);
            }
            else if(P[Position[3]][Position[2]].type==3 && J[j].P.marchandise==1 && action[*type-1]!=1)  //Si case Trésor
            {
                J[j].doublons=J[j].doublons+TRESOR;
                J[j].P.marchandise=0;
                action[*type-1]=1;
                J[j].P.coordonee[0]=Position[3];
                J[j].P.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=1;
                P[Position[3]][Position[2]].joueur=j;
                Mr_Propre(type, tab, P, Position,j,action,J);
            }
            else if(J[j].Pioche.dev[1]==1 && action[*type-1]!=1 && J[j].P.marchandise==1 && P[Position[3]][Position[2]].type>=4)  //Si Port (Bonus Carte Dev)
            {
                J[j].doublons=J[j].doublons+BONUS_PIRATES;
                J[j].P.marchandise=0;
                action[*type-1]=1;
                J[j].P.coordonee[0]=Position[3];
                J[j].P.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=1;
                P[Position[3]][Position[2]].joueur=j;
                Mr_Propre(type, tab, P, Position,j,action,J);
            }
            else
            {
                J[j].P.coordonee[0]=Position[3];
                J[j].P.coordonee[1]=Position[2];
                P[Position[3]][Position[2]].bateau=1;
                P[Position[3]][Position[2]].joueur=j;
                Mr_Propre(type, tab, P, Position,j,action,J);
            }
        }
        else  //si c'est un marchand
        {
            //En cas de Case Port (et selon la case)
            if(P[Position[3]][Position[2]].type==4 && J[j].M.marchandise!=0 && action[*type-1]!=1)
            {
                Vente_Marchandises(type,tab,action,J,P,j,Position,4);
            }
            else if(P[Position[3]][Position[2]].type==5 && J[j].M.marchandise!=0 && action[*type-1]!=1)
            {
                Vente_Marchandises(type,tab,action,J,P,j,Position,5);
            }
            else if(P[Position[3]][Position[2]].type==6 && J[j].M.marchandise!=0 && action[*type-1]!=1)
            {
                Vente_Marchandises(type,tab,action,J,P,j,Position,6);
            }
            else if(P[Position[3]][Position[2]].type==7 && J[j].M.marchandise!=0 && action[*type-1]!=1)
            {
                Vente_Marchandises(type,tab,action,J,P,j,Position,7);
            }
            else if(P[Position[3]][Position[2]].type==8 && J[j].M.marchandise!=0 && action[*type-1]!=1)
            {
                Vente_Marchandises(type,tab,action,J,P,j,Position,8);
            }
            else if(P[Position[3]][Position[2]].type==1 || action[*type-1]!=1) //si case mer ou action non effectué
            {
                Mr_Propre(type, tab, P, Position,j,action,J);
                P[Position[3]][Position[2]].bateau=0;
                J[j].M.coordonee[0]=Position[3];
                J[j].M.coordonee[1]=Position[2];

            }
            else if(action[*type-1]==1) //si action effectué
            {
                Messages(5);
            }
        }
    }
}

void Case_Prise(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j, int Position[])
{
    /**Action à Effectuer en cas de case non libre**/
    if(Position[2]<0 || Position[2]>Long-1 || Position[3]<0 || Position[3]>Larg-1)  //Vérification que le plateau n'est pas dépassé
    {
        Messages(4);
    }
    else if((P[Position[3]][Position[2]].type==0) || (P[Position[3]][Position[2]].type==2) || (((*type==1)||(*type==2)) && ((P[Position[3]][Position[2]].type==4) || (P[Position[3]][Position[2]].type==5) || (P[Position[3]][Position[2]].type==6) || (P[Position[3]][Position[2]].type==7) || (P[Position[3]][Position[2]].type==8))))  //Vérification ni Côtes, ni Mer lointaine
    {
        Messages(1); //Vérification du type de case et des bateaux qui peuvent y accéder
    }
    else if(*type==3 && P[Position[3]][Position[2]].type==J[j].M.type_marchandise)  //Vérification du type de marchandise avant l'arrivée dans le port
    {
        Messages(3);
    }
    else if(action[*type-1]==1 && (*type==1 || *type==2))
    {
        Messages(5);
    }
    else
    {
        if(*type==1)  //si c'est une frégate
        {
            if(P[Position[3]][Position[2]].bateau==1 && P[Position[3]][Position[2]].joueur !=j) //Pirates ne nous appartenant pas
            {
                Messages(9);
                P[Position[3]][Position[2]].etat=0;
                J[P[Position[3]][Position[2]].joueur].P.statut=0, J[P[Position[3]][Position[2]].joueur].P.marchandise=0;
                J[j].doublons=J[j].doublons+TOUCHE_COULE;
                action[*type-1]=1;
            }
            else if(P[Position[3]][Position[2]].joueur ==j || P[Position[3]][Position[2]].joueur==((tab[3]+1)%2)) //Pirates nous appartenant
            {
                Messages(2);
            }
            else if(P[Position[3]][Position[2]].bateau==0) //Bateau de Marchandises
            {
                Messages(7);
            }
        }
        else if(*type==2)  //si c'est un pirate
        {
            if(P[Position[3]][Position[2]].bateau==0 && P[Position[3]][Position[2]].joueur !=j)
            {
                if(J[j].P.marchandise==1) //Bateau Plein(plus de place)
                {
                    Messages(10);
                }
                else if(J[P[Position[3]][Position[2]].joueur].M.marchandise==1) //Attaque de marchand ayant 1 Marchandise
                {
                    Messages(11);
                    P[Position[3]][Position[2]].etat=0;
                    J[P[Position[3]][Position[2]].joueur].M.statut=0, J[P[Position[3]][Position[2]].joueur].M.marchandise=0;
                    J[j].P.marchandise=1;
                    J[j].doublons=J[j].doublons+MARCHAND_ATTAQUE;
                    action[*type-1]=1;
                    if(J[P[Position[3]][Position[2]].joueur].Pioche.dev[0]==1)  //Si assurance joueur attaqué
                    {
                        J[P[Position[3]][Position[2]].joueur].doublons=J[P[Position[3]][Position[2]].joueur].doublons+ASSURANCE_COULE;
                    }
                }
                else //Attaque de marchand ayant plusieurs Marchandise
                {
                    Messages(11);
                    J[P[Position[3]][Position[2]].joueur].M.marchandise--;
                    J[j].P.marchandise++;
                    action[*type-1]=1;
                    J[j].doublons=J[j].doublons+MARCHAND_ATTAQUE;
                }
            }
            else if(P[Position[3]][Position[2]].joueur ==j || P[Position[3]][Position[2]].joueur==(tab[3]+1)%2) //Attaque Ami
            {
                Messages(2);
            }
            else if(P[Position[3]][Position[2]].bateau==0 || P[Position[3]][Position[2]].bateau==1) //Attaque
            {
                Messages(7);
            }
        }
        else  //si c'est un marchand
        {
            Messages(8);
        }
        //Netoyage après passage et -1 déplacement
    }
}

void Verification_Case(int *type, int tab[], int action[], Joueur J[], S_Case P[][Long], fregate F[], int j)
{
    /**Vérification de la case choisie**/
    int i, fin=1, x,y, Position[4];
    do
    {
        system("cls");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("|                                         Black Fleet/Déplacement                                        |\n");
        printf("|--------------------------------------------------------------------------------------------------------|\n");
        printf("        Joueur : ");
        color(J[j].couleur,BLEU);
        printf("%s\n",J[j].nom);
        color(BLANC,NOIR);
        printf("        Doublons : %d\n\n",J[j].doublons);
        Affichage_Plateau(P,J,F);
        printf("\n Déplacez vous avec les flèches directionnelles ");
        i=0;
        while(i!=HAUT && i!=BAS && i!=DROITE && i!=GAUCHE && i!=ECHAP)
        {
            i=getch();
        }
        if(*type==1)  //si c'est une frégate
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
        case HAUT: //Fléche du Haut
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
        case BAS: //Fléche du Bas
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
        case GAUCHE: //Fléche de Gauche
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
        case DROITE: //Fléche de Droite
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
    /**Déplacement et Action de Chaque Joueur**/
    int choix, Action[3]= {0,0,0};
    do
    {
        choix=Choix_Dep(tab,J[j]);
        switch(choix)
        {
        case 1: //Si Frégate
            if (tab[0]>0) //si il reste des déplacements
            {
                while((tab[0]>0 || Action[0]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                    if(tab[0]<=0){
                        Action[0]=1;
                    }
                }
            }
            else
            {
                Messages(0);
            }
            break;
        case 2: // Si Pirates
            if (tab[1]>0)
            {
                while((tab[1]>0 || Action[1]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                    if(tab[1]<=0){
                        Action[1]=1;
                    }
                }
            }
            else
            {
                Messages(0);
            }
            break;
        case 3: //Si Marchands
            if (tab[2]>0)
            {
                while((tab[2]>0 || Action[2]!=1) && choix!=0)
                {
                    Verification_Case(&choix,tab,Action,J,P,F,j);
                    if(tab[2]<=0){
                        Action[2]=1;
                    }
                }
            }
            else
            {
                Messages(0);
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
