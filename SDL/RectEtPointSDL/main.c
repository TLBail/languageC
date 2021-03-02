#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>


#include <time.h>


SDL_Renderer* pRenderer{ nullptr }; // mon rendu

int main(int argc, char* argv[]) 
{     

    #pragma region init
    if (SDL_Init(SDL_INIT_VIDEO) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        return EXIT_FAILURE;     
    }       
    SDL_Window* pWindow{ nullptr }; // ma fenêtre 
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }           

    SDL_SetWindowTitle(pWindow, "Salutatoi");
    SDL_Event event;
    int isOpen = 1;


    #pragma endregion



    //initialisation des valeur
    srand(time(NULL));
    SDL_Point point[100];

    for (size_t i = 0; i < 100; i++)
    {

            SDL_Point pointe = {rand() % (800 - 0 + 1), rand() % (600 - 0 + 1)};
            point[i] = pointe;
    }

    SDL_Rect rectangle{20, 30, 100, 50};


    //boucle principale
    while (isOpen)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type) /* On teste le type d'événement */
            {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                isOpen = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            }
        }

        //placement au hasard des point
        for (size_t i = 0; i < 100; i++)
        {
            point[i].x = rand() % (800 - 0 + 1);
            point[i].y = rand() % (600 - 0 + 1);
            
        }
        

        
        //fond noir
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);
        
        
        //affichage des point
        for (size_t i = 0; i < 100; i++)
        {
            SDL_SetRenderDrawColor(pRenderer, rand() % 256, rand() % 256, rand() % 256 , 255);
            SDL_RenderDrawPoint(pRenderer, point[i].x, point[i].y);
        
        }
        
        //affichage du rectangle
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(pRenderer, &rectangle);
       
        SDL_RenderPresent(pRenderer);

        
        
    }



    #pragma region ending

    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}