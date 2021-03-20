#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structure.h"



int main(int argc, char const *argv[])
{
    printf("Programe de test des structure\n");

    Vector2 ptitPos = {34.45f, 765.76f};

    displayVector2(ptitPos);
    moveVector2(&ptitPos, 5);
    displayVector2(ptitPos);

    return 0;
}
