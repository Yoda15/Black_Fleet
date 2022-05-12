#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Declarations_Variables.h"
#include "Module_Jeux/Message.h"

void Choix(int *j, int *variable)
{
    int i;
    while(i!=DROITE && i!=GAUCHE && i!=ESPACE)
    {
        i=getch();
    }
    switch(i)
    {
    case GAUCHE: //Fléche de Gauche
        (*variable)--;
        if(*j==3 && *variable<1){
            Messages(21);
            (*variable)++;
        }
        else if(*j==2 && *variable<1){
            Messages(21);
            (*variable)++;
        }
        else if(*j==1 && *variable<1){
            Messages(21);
            (*variable)++;
        }
        break;
    case DROITE: //Fléche de Droite
        (*variable)++;
        if(*j==3 && *variable>4){
            Messages(21);
            (*variable)--;
        }
        else if(*j==2 && *variable>3){
            Messages(21);
            (*variable)--;
        }
        else if(*j==1 && *variable>3){
            Messages(21);
            (*variable)--;
        }
        break;
    case ESPACE:
        (*j)--;
        break;
    }
}

void Option(int *nbj,int *difficulte,int *vitesse)
    {
        int i=3;
        Messages(20);
        do
        {
            system("cls");
            printf("|--------------------------------------------------------------------------------------------------------|\n");
            printf("|                                                                                                        |\n");
            printf("|-----------------------------------------------Black Fleet----------------------------------------------|\n");
            printf("|                                                                                                        |\n");
            printf("|--------------------------------------------------------------------------------------------------------|\n");
            if(i==3)
            {
                printf("|                                      < Nombre de Joueur : %d >                                     |\n", *nbj);
                Choix(&i,nbj);
            }
            else if(i==2)
            {
                printf("|                                      < Difficulté : %d >                                           |\n", *difficulte);
                Choix(&i,difficulte);
            }
            else if(i==1)
            {
                printf("|                                      < Vitesse de Jeu : %d >                                          |\n", *vitesse);
                Choix(&i,vitesse);
            }
        }while(i!=0);
    }
