#include <stdio.h>
#include <stdlib.h>

#include "enum.h"

int main(int argc, char const *argv[])
{
    printf("Programe de test des enum\n");

    Difficulter actualDif = MOYEN;

    printf("diffilculter actuel : %d\n", actualDif);

    printf("choisiser votre nouvelle difficulter \n1: Facile\n 2: moyen\n 3:Difficile\n");
    Difficulter newdif;
    scanf("%d", &newdif);
    switch (newdif)
    {
    case FACILE:
        printf("ok t dans le noob tier\n");
        break;
    case MOYEN:
        printf("ok tier\n");
        break;
    case DIFFICILE:
        printf("bien bien j'aime bien\n");
        break;

    default:
        printf("on a dit 1 , 2 ou 3 toto \n");
        break;
    }
    return 0;
}
