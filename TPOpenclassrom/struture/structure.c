//affiche un vecteur dans la console
void displayVector2(Vector2 vectorToDisplay){
    printf("x = %.4f\n", vectorToDisplay.x);
    printf("y = %.4f\n", vectorToDisplay.y);
}

//mutiplie un vecteur

void moveVector2(Vector2* vectorToMove, int force){
    vectorToMove->x = vectorToMove->x * force;
    vectorToMove->y = vectorToMove->y * force;
}