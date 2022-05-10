#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../Objets.h"


void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void nom_couleur(Joueur J,char t[])
{
    switch(J.M.type_marchandise)
    {
    case 4:
        t[0]='C';
        t[1]='y';
        t[2]='\0';
        break;
    case 5:
        t[0]='V';
        t[1]='e';
        t[2]='\0';
        break;
    case 6:
        t[0]='O';
        t[1]='r';
        t[2]='\0';
        break;
    case 7:
        t[0]='V';
        t[1]='i';
        t[2]='\0';
        break;
    case 8:
        t[0]='R';
        t[1]='o';
        t[2]='\0';
        break;
    default:
        printf("Houston, on a un problème");
    }
}
