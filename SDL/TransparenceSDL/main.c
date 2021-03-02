#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>


#include <time.h>
#include <math.h>


int main(int argc, char* argv[]) 
{     

    #pragma region init
    if (SDL_Init(SDL_INIT_VIDEO) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        return EXIT_FAILURE;     
    }       
    SDL_Window* pWindow{ nullptr }; // ma fenêtre 
    SDL_Renderer* pRenderer{ nullptr }; // mon rendu

    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }           

    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);

    SDL_SetWindowTitle(pWindow, "Salutatoi");
    SDL_Event event;
    int isOpen = 1;


    #pragma endregion



    //initialisation des valeur

    //creation du point centraux
    SDL_Point centerpoint{400, 300};


    //creation des 2 point
    SDL_Point startpoint;
    SDL_Point endpoint;

    
    SDL_Rect rectangle{20, 30, 100, 50};


    double deg = 0,  size = 200;


    //boucle principale
    while (isOpen)
    {
        #pragma region event
        while (SDL_PollEvent(&event))
        {
            switch(event.type) /* On teste le type d'événement */
            {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                isOpen = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            }
        }

        #pragma endregion event

        //calcul des position des point
        deg += .01f;
        startpoint.x = centerpoint.x + cos(deg) * size;
        startpoint.y = centerpoint.y + sin(deg) * size;

        endpoint.x = centerpoint.x + cos(deg) * size * -1;
        endpoint.y = centerpoint.y + sin(deg) * size * -1;
        
        rectangle.x = centerpoint.x + cos(deg + 2) * size;
        rectangle.y = centerpoint.y + sin(deg + 2) * size;

        rectangle.w = (centerpoint.x + cos(deg + 2) * size * -1) - rectangle.x;
        rectangle.h = (centerpoint.y + sin(deg + 2) * size * -1) - rectangle.y;
        

        //fond noir
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);
        
        //dessin line
        SDL_SetRenderDrawColor(pRenderer, 255,0,255,255);
        SDL_RenderDrawLine(pRenderer, startpoint.x, startpoint.y, endpoint.x ,endpoint.y);
        
        //dessin rectangle
        SDL_SetRenderDrawColor(pRenderer, 255,0,0,100);
        SDL_RenderFillRect(pRenderer, &rectangle);




        //rendu final
        SDL_RenderPresent(pRenderer);

        SDL_Delay(2);


    }



    #pragma region ending

    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}