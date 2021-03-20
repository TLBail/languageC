//==============================================================
// Programme : Mastermind
//
// Role :     Jouer au masterMind
//
// Principe : trouver un code aléatoire de 5 chiffre de 1 a 9
//
// Auteur :           Théo LE BAIL
//
//==============================================================

//lib
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//constante du master mind
#define NBTROU 5
#define NBCOULEUR 9


#include "masterMind.h"
    





int main(int argc, char const *argv[])
{
    printf("Mastermind \n\n");


    //init des variable
    int codeSecret[NBTROU], bp, ml, 
        codeEssai[NBTROU], nbEssai = 0;

    //generation du code secret
    choisirSolution(codeSecret, 1);

    //affichage
    printf("Code secret : ");
    for (size_t i = 0; i < NBTROU; i++)
    {
        printf("X");
    }
    printf("\n\n");

    for (size_t i = 0; i < NBTROU; i++)
    {
        printf("%d", codeSecret[i]);
    }
    printf("\n");
    
    do
    {
        nbEssai++;
        printf("%d - ", nbEssai);
        entrerEssai(codeEssai);
        bp = bienPlaces(codeSecret, codeEssai);
        ml = malPlaces(codeSecret, codeEssai);
        afficherResultat(bp, ml);
    } while (bp < NBTROU);
    
    printf("Felicitations tu as reussi !!\n");

    
    



    return 0;

}


