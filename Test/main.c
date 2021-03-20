#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Test de getline de marde");

    char * msg;
    size_t lgMsg;

    std::getline(&msg, &lgMsg, stdin);

    printf("salut a tous c %s", msg);
    return 0;
}
