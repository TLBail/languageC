#include <stdio.h>

double moyenneTab(int tableau[], int tailleTab);

int main(int argc, char const *argv[])
{
    int tab[10] = {1,34, 12, 32, 23,55, 54, 23 ,53, 14};

    printf("la moyenne du tableau vaut : %lg\n", moyenneTab(tab, 10));

    return 0;
}


double moyenneTab(int tableau[], int tailleTab){

    double somme = 0;

    for (size_t i = 0; i < tailleTab; i++)
    {   
        somme += tableau[i];
    }

    return somme / tailleTab; 
    
}