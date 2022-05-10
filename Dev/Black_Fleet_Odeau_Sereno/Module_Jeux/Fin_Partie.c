#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Objets.h"
#include "../Affichage/Couleurs.h"

void Fin_de_partie(Joueur J[])
{
    int tableau_final[4],i=0,j=0;
    for(i=0;i<NBJ;i++)
    {
        if(J[i].Pioche.Fin_Partie==1)
        {
            tableau_final[i]=J[i].doublons;
        }
        else
        {
            tableau_final[i]=-1;
        }
    }
    for(i=1;i<NBJ;i++)
    {
        if(tableau_final[j]<tableau_final[i])
        {
            j=i;
        }
    }
    color(4,0);
    printf("Bravo %s! Vous êtes le plus grand pirate du monde !",J[j].nom);
    Sleep(5000);
    color(15,0);

}
