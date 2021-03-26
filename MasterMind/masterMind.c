//t est le tableau contenant la solution générée
//redondance = 0 pour non et 1 pour oui
void choisirSolution(int t[5], int redondance)
{
    srand((unsigned long)time(NULL));
    int nvEntier, isDifferent = 1;
    //generation du code secret
    for (size_t i = 0; i < NBTROU; i++)
    {
        if (redondance == 0)
        {

            do
            {
                isDifferent = 1;
                nvEntier = rand() % NBCOULEUR + 1;
                for (size_t i = 0; i < NBTROU; i++)
                {
                    if (nvEntier == t[i])
                    {
                        isDifferent = 0;
                        break;
                    }
                }
            } while (isDifferent == 0);
        }
        else
        {
            nvEntier = rand() % NBCOULEUR + 1;
        }

        t[i] = nvEntier;
    }
}

//t est le tableau qui contient l'essai saisi
void entrerEssai(int t[NBTROU])
{
    char msg[100];
    char str[2];
    printf("Entrer votre essai  ");
    scanf("%s", &msg);
    for (size_t i = 0; i < NBTROU; i++)
    {

        str[0] = msg[i];
        str[1] = '\0';
        t[i] = (int)strtol(str, NULL, 10);
    }
}

//s est le tableau contenant la solution (secret)
//e est le tableau contenant l'essai
int malPlaces(int s[5], int e[5])
{
    int sum = 0;
    for (size_t i = 0; i < NBTROU; i++)
    {
        for (size_t j = 0; j < NBTROU; j++)
        {
            if (s[i] == e[j] && s[i] != e[i] && e[j] != s[j])
            {
                sum++;
                break;
            }
        }
    }

    return sum;
}

//s est le tableau contenant la solution (secret)
//e est le tableau contenant l'essai
int bienPlaces(int s[5], int e[5])
{
    int sum = 0;
    for (size_t i = 0; i < NBTROU; i++)
    {
        if (s[i] == e[i])
            sum++;
    }
    return sum;
}

// bp est le nombre de pions bien placés
// mp est le nombre de pions mal placés
void afficherResultat(int bp, int mp)
{
    printf("    bien places %d , ", bp);
    printf("mal places %d\n", mp);
}
