#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../Declarations_Variables.h"
#include "../Objets.h"
#include "Couleurs.h"



void Affichage_Plateau(S_Case P[][Long],Joueur J[],fregate F[]);
void Affichage_Bateau(S_Case P[][Long],fregate F[],int i,int j,Joueur J[],int c);


S_Case P[Larg][Long];
void Affichage_Plateau(S_Case P[][Long],Joueur J[],fregate F[])
{
    int i=0,j=0,k=0,c=0;
    for (i=0; i<Larg; i++)
    {
        for (j=0; j<Long; j++)
        {
            printf("|");
            switch(P[i][j].type)
            {
            case 0:  // Terre
                color(2,2);
                printf("%10d",P[i][j].type);
                break;
            case 2:  // Mer lointaine
                c=1;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 3:  // Tr�sor
                c=14;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 4:  // Port d'outils
                c=3;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 5:  // Port de riz
                c=10;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 6:  // Port de bl�
                c=12;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 7:  // Port d'�rable
                c=5;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            case 8:  // Port de vin
                c=4;
                Affichage_Bateau(P,F,i,j,J,c);
                break;
            default:  // Mer
                c=9;
                Affichage_Bateau(P,F,i,j,J,c);

            }
            color(15,0);
        }
        printf("\n");
        for(k=0; k<((10*Long)+Long); k++)
        {
            printf("-");
        }
        printf("\n");
    }
    printf("\n ______________________________________________________________________________________________________________\n");
    printf("| Port d'outils (cyan)|  Port de riz (vert) | Port de bl� (orange)|Port d'�rable(magenta)| Port de vin (rouge) |\n");
    printf("|---------------------+---------------------+---------------------+----------------------+---------------------|\n");
    printf("| outils : // doublons| outils : 1 doublon  | outils : 3 doublons | outils : 3 doublons  | outils : 2 doublons |\n");
    printf("| riz : 1 doublon     | riz : // doublons   | riz : 2 doublons    | riz : 2 doublons     | riz : 3 doublons    |\n");
    printf("| bl� : 3 doublons    | bl� : 2 doublons    | bl� : // doublons   | bl� : 1 doublon      | bl� : 2 doublons    |\n");
    printf("| �rable : 2 doublons | �rable : 3 doublons | �rable : 1 doublon  | �rable : // doublons | �rable : 2 doublons |\n");
    printf("| vin : 2 doublons    | vin : 2 doublons    | vin : 3 doublons    | vin : 2 doublons     | vin : // doublons   |\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

}

void Affichage_Bateau(S_Case P[][Long],fregate F[],int i,int j,Joueur J[],int c)
{
    char t[3];
    if(P[i][j].etat==1)
    {
        switch(P[i][j].bateau)
        {
        case 0:
            color(J[(P[i][j].joueur)].couleur,c);
            nom_couleur(J[(P[i][j].joueur)],t);
            printf(" Mar-%d-%s ",J[(P[i][j].joueur)].M.marchandise,t);
            break;
        case 1:
            color(J[(P[i][j].joueur)].couleur,c);
            printf(" Pirate-%d ",J[(P[i][j].joueur)].P.marchandise);
            break;
        case 2:
            color(F[0].couleur,c);
            printf(" Fr�gate  ");
            break;
        case 3:
            color(F[1].couleur,c);
            printf(" Fr�gate  ");
            break;
        }
    }
    else
    {
        color (c,c);
        printf("%10d",P[i][j].type);

    }
}
