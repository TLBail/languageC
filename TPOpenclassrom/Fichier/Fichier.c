
void dspFile(FILE *file){
    rewind(file);
    char *msg = malloc(BUFFERSIZE);
    fgets(msg, BUFFERSIZE, fichier);
    printf("affichage d'une ligne du fichier\n");
    printf("%s\n", msg);
    
}