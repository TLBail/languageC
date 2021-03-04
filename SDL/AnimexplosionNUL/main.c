#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>


#include <time.h>
#include <math.h>

#define NBLINE 20
#define WIDTH 800
#define HEIGHT 600

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

    //creation du point centraux
    SDL_Point centerpoint{400, 300};


    //creation des 2 point
    SDL_Point startpoint[NBLINE];
    SDL_Point endpoint[NBLINE];

    //rectangle
    SDL_Rect rectangle;

    double deg = 0, size = 101, toAdd = .01f;
    int i = -1;

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
        if(i >= NBLINE) i = -1;
        i++;

        deg += .01f;
        if(size > WIDTH / 2){
         toAdd = -toAdd;   
        }

        if(size < 100){
            toAdd = -toAdd;
        }
        size += toAdd;
        startpoint[i].x = centerpoint.x + cos(deg + i * .5f) * size;
        startpoint[i].y = centerpoint.y + sin(deg + i * .5f) * size;

        /*
        endpoint[i].x = centerpoint.x + cos(deg + i * .5f) * size * -1;
        endpoint[i].y = centerpoint.y + sin(deg + i * .5f) * size * -1;
        */
        endpoint[i].x = centerpoint.x + cos(deg + i * .5f) * size / 10;
        endpoint[i].y = centerpoint.y + sin(deg + i * .5f) * size / 10;
        
        
        //calcul rectangle
        rectangle.x = centerpoint.x + cos(deg + 2) * size / 10;
        rectangle.y = centerpoint.y + sin(deg + 2) * size / 10;

        rectangle.w = (centerpoint.x + cos(deg + 2) * size / 10 * -1) - rectangle.x;
        rectangle.h = (centerpoint.y + sin(deg + 2) * size / 10 * -1) - rectangle.y;
        
        //fond noir
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);
        
        //dessin line
        SDL_SetRenderDrawColor(pRenderer, rand() % 255,rand() % 255,rand() % 255,255);
        SDL_RenderDrawLine(pRenderer, startpoint[i].x, startpoint[i].y, endpoint[i].x ,endpoint[i].y);
        
        //dessin rectangle
        SDL_SetRenderDrawColor(pRenderer, 255,0,0,100);
        SDL_RenderFillRect(pRenderer, &rectangle);

        //rendu final
        SDL_RenderPresent(pRenderer);



    }



    #pragma region ending

    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}