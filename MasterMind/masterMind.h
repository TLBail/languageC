#ifndef DEF_MASTERMIND
    #define DEF_MASTERMIND 

    #include "masterMind.c"
    
    //t est le tableau contenant la solution générée
    //redondance = 0 pour non et 1 pour oui
    void choisirSolution(int t[NBTROU], int redondance);

    //t est le tableau qui contient l'essai saisi
    void entrerEssai(int t[NBTROU]);

    //s est le tableau contenant la solution (secret)
    //e est le tableau contenant l'essai
    int malPlaces(int s[5], int e[5]);

    //s est le tableau contenant la solution (secret)
    //e est le tableau contenant l'essai
    int bienPlaces(int s[5], int e[5]);

    // bp est le nombre de pions bien placés
    // mp est le nombre de pions mal placés
    void afficherResultat(int bp, int mp);

    
#endif



