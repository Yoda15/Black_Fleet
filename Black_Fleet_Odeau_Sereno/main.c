#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Declarations_Variables.h"
#include "Objets.h"
#include "Joueur.h"
#include "Fonctions_Initialisation.h"

int main()
{
    Joueur J[NBJ];
    SetConsoleOutputCP(1252); //permet d'afficher les accents
    Initialisation(J);
    return 0;
}
