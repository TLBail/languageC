#include <stdio.h>

#define TABSIZE 10


void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);

int main(int argc, char const *argv[])
{
    
    int tab1[TABSIZE] = {1, 35, 24 ,24, 225, 24567};

    int tab2[TABSIZE];

    copie(tab1, tab2, TABSIZE);

    for (size_t i = 0; i < TABSIZE; i++)
    {
        printf("valeur : %d\n" , tab2[i]);
    }
    
    return 0;
}


void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau){

    for (size_t i = 0; i < tailleTableau; i++)
    {
        tableauCopie[i] = tableauOriginal[i];
    }
    


}




