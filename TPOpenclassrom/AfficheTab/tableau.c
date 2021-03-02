#include <stdio.h>

void affiche(int tableau[], int tailleTab);


int main(int argc, char const *argv[])
{
    int tailleTab = 5;
    int tableau[5] = {0,1,2,3,4};

    affiche(tableau, tailleTab);
    printf("test avec un changement \n");
    affiche(tableau, tailleTab);
    return 0;
}


void affiche(int tableau[], int tailleTab){
    
    
    for (size_t i = 0; i < tailleTab; i++)
    {
        printf("valeur : %d\n", tableau[i]);
    }
    tableau[1] = 3;
    
    
}

