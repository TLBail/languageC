#ifndef DEF_STRUCTURE
    #define DEF_STRUCTURE
    
    
    typedef struct Vector2 Vector2;
    struct Vector2
    {
        float x;
        float y;
    };
    
    void displayVector2(Vector2 vectorToDisplay);

    void moveVector2(Vector2* vectorToMove, int force);

    #include "structure.c"

#endif






