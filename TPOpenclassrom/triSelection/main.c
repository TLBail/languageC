#include <stdio.h>

#include "tableaux.h"

#define TABSIZE 10

void ordonnerTableau(int tableau[], int tailleTableau);

int main(int argc, char const *argv[])
{
    int tableauAtrier[TABSIZE] = {2, 45, 53, 4, 23, 24};

    ordonnerTableau(tableauAtrier, TABSIZE);

    for (size_t i = 0; i < TABSIZE; i++)
    {
        printf("valeur : %d\n", tableauAtrier[i]);
    }
    

    return 0;
}


void ordonnerTableau(int tableau[], int tailleTableau){
    int *min = NULL;
    
    for (size_t i = 0; i < tailleTableau - 1; i++)
    {
        min = &tableau[i];
        for (size_t j = i + 1 ; j < tailleTableau; j++)
        {
            if(*min > tableau[j]) min = &tableau[j];
                          
        }
        echangerValeur(min, &tableau[i]);
        
    }


    

}
