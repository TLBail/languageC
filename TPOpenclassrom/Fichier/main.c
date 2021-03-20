#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fichier.h"

#define BUFFERSIZE sizeof(char[256])

int main(int argc, char const *argv[])
{
    printf("salut et bienvenue sur le programe des fichier\n");

    FILE *fichier = NULL;

    fichier = fopen("test.txt", "r+");

    //si le fichier est null alors sa veut dire que l'ouverture a echouer
    if(fichier == NULL) return 1;

    char *msg = malloc(BUFFERSIZE);
    while (fgets(msg, BUFFERSIZE, fichier) != NULL);
    {
        printf("%s\n", msg);
    }
    
    printf("sa te dit de le modifier le fichier Y/N");
    char rep;
    scanf("%c", &rep);
    if(rep == 'Y'){
        printf("met la chaine de caractère que tu veux mettre ");
        char msg3[256];
        scanf("%s", msg3);
        fputs(strcat(msg3, "\n"), fichier);
        rewind(fichier);
        while (fgets(msg, BUFFERSIZE, fichier) != NULL);
        {
            printf("%s\n", msg);
        }
    }

    free(msg);
    fclose(fichier);

    return 0;
}
