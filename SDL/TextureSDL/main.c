#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_image.h>


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

    //transparence
    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
    //nom fenetre
    SDL_SetWindowTitle(pWindow, "Salutatoi");
    

    
    SDL_Event event;
    int isOpen = 1;


    #pragma endregion

    //chargement img
    SDL_Surface* image = IMG_Load("./data/duck.jpg");
    SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(pRenderer, image);


    //initialisation des valeur

    SDL_FreeSurface(image);
    SDL_Rect src{0, 0, 0, 0};
    SDL_Rect dst{ 0, 0, 400, 300 };
    SDL_QueryTexture(pTextureImage, nullptr, nullptr, &src.w, &src.h);
    

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

      

        
        //rendu img
        
        SDL_RenderCopy(pRenderer, pTextureImage, nullptr, nullptr);   
        SDL_RenderCopy(pRenderer, pTextureImage, &src, &dst);
    

        //rendu final
        SDL_RenderPresent(pRenderer);

        SDL_Delay(2);


    }



    #pragma region ending
    SDL_DestroyTexture(pTextureImage);
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}