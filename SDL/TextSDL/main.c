#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_image.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_ttf.h>


#include <time.h>
#include <math.h>

#define WIDTHSCREEN 600
#define HEIGHTSCREEN 800

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

    //transparence
    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
    //nom fenetre
    SDL_SetWindowTitle(pWindow, "Salutatoi");
    
    //init SDL TTF
    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }
    
    
    SDL_Event event;
    int isOpen = 1;

    


    #pragma endregion

    TTF_Font* font = TTF_OpenFont("./data/esparac.ttf", 18); // Crée un police avec la police "ariali.ttf" et de taille 18 pixels
    

    if (font == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

    }

    SDL_Surface* text = TTF_RenderText_Blended(font, "Hello,aorld", SDL_Color{ 0, 255, 0, 255 }); // Crée un surface qui contient le texte

    if (text == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, text); // Crée la texture qu'on va afficher a partir de la surface

    if (texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position;

    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h); // Récupere la dimension de la texture

    // Centre la texture sur l'écran
    position.x = WIDTHSCREEN / 2 - position.w / 2;
    position.y = HEIGHTSCREEN / 2 - position.h / 2;


    // Libération des resource de la police et de la surface qui contient le texte
    SDL_FreeSurface(text);
    TTF_CloseFont(font);

    

    //initialisation des valeur



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

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); 
        SDL_RenderClear(pRenderer);  


        SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);
        SDL_RenderCopy(pRenderer, texture, nullptr, &position);



        //rendu final
        SDL_RenderPresent(pRenderer);

    }



    #pragma region ending

    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);
    TTF_Quit();
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}