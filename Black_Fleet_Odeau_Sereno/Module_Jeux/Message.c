#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../Affichage/Couleurs.h"



void Messages(int a){
    /**Permet de Centraliser les Messages**/
    color(ROUGE,NOIR);
    switch(a){
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
        printf("\nMorbleu !, nous ne sommes pas des pirates !!!");
        break;
    case 8:
        printf("\nMousaillon, Navire droit devant, changement de cap � effectuer !");
        break;
    case 9:
        printf("\nBranle-bas de combat !");
        break;
    case 10:
        printf("\nVous �tes saoule capitaine, il n'y a plus de place !");
        break;
    case 11:
        printf("\nPas de quartier !");
        break;
    case 12:
        printf("\nAnnulation de l'achat...");
        break;
    case 13:
        printf("Merci d'acheter toutes les autres cartes avant !");
        break;
    case 14:
        printf("\nCarte D�j� Achet�...");
        break;
    case 15:
        printf("\nAchat Effectu� !");
        break;
    case 16:
        printf("\nArgent Insuffisant...");
        break;
    case 17:
        printf("\nPlus De Place... !");
        break;
    case 18:
        printf("Couleur D�j� Selectionn� ! Merci d'en choisir une autre.");
        break;
    }
    color(BLANC,NOIR);
    Sleep(2000);
}
