#include <stdio.h>

#define TABSIZE 10

void maximumTableau(int tableau[], int tailleTableau, int valeurMax);



int main(int argc, char const *argv[])
{
    int tab1[TABSIZE] = {32, 435, 6, 323, 436};

    maximumTableau(tab1, TABSIZE, 20);

    for (size_t i = 0; i < TABSIZE; i++)
    {
        printf("valeur : %d\n", tab1[i]);
    }
    
    return 0;
}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax){

    for (size_t i = 0; i < tailleTableau; i++)
    {
        if(tableau[i] > valeurMax) tableau[i] = 0;
    }
    
}


