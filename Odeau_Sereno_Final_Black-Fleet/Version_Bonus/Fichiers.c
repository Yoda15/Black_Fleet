#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


void Affichage_Fichier_ESTACA(){
    FILE* Fichier;
    Fichier =fopen("ESTACA.txt","r");
    char Affichage[200];
    while( fgets(Affichage,200,Fichier) )
        printf("%s",Affichage);
    fclose(Fichier);
}



void Affichage_Fichier_SON(){
    FILE* Fichier;
    Fichier =fopen("SON.txt","r");
    char Affichage[200];
    while( fgets(Affichage,200,Fichier) )
        printf("%s",Affichage);
    fclose(Fichier);
}
