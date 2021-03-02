#include <stdio.h>

int sommeTab(int tableau[], int tailleTab);

int main(int argc, char const *argv[])
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("la somme du tableau vaut : %d\n", sommeTab(a, 10));
    
    return 0;
}


int sommeTab(int tableau[], int tailleTab){
    int somme = 0;

    for (size_t i = 0; i < tailleTab; i++)
    {
        somme += tableau[i];
    }

    return somme;
    
}


