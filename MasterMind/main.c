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
    int codeSecret[NBTROU], bp, ml, redondance,
        codeEssai[NBTROU], nbEssai = 0;

    //on attend que l'utilisateur met 1 ou 0
    while (1)
    {
    
        printf("Voulez vous avec ou sans redondance du code secret\n");
        printf("0 avec redondance 1  sans redondance\n");
        scanf("%d", &redondance);
        while(getchar()!='\n');
    }
    
    //generation du code secret zero sans redondance 1 avec redondance
    choisirSolution(codeSecret, redondance);

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
    } while (bp < NBTROU  && nbEssai < 12);

    //si le joueur a trouvé le bon code 
    if(bp >= NBTROU){
        printf("Felicitations tu as reussi !!\n");        
    }else{ // sinon il a n'a pas trouvé le bon code 
        printf("trop d'essai tu as echouer");
    }

    
    



    return 0;

}


