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
    

    
    SDL_Event events;
    int isOpen = 1;


    #pragma endregion


    //initialisation des valeur



    //boucle principale
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch(events.type) /* On teste le type d'événement */
            {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                isOpen = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            case SDL_KEYDOWN:
                SDL_Log("+key");

                if (events.key.keysym.scancode == SDL_SCANCODE_W) // Regarde si le scancode W est enfoncé (Z sous un azerty)
                    SDL_Log("Scancode W"); // Affiche un message

                if (events.key.keysym.sym == SDLK_w) // Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                    SDL_Log("Keycode W"); // Affiche un message

                if (events.key.keysym.sym == SDLK_z) // Regarde si on appuyer sur la touche Z (la touche Z sous un azerty)
                    SDL_Log("Keycode Z"); // Affiche un message

                break;
            case SDL_MOUSEMOTION: // Déplacement de souris
                SDL_Log("Mouvement de souris");
                SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
                break;
            case SDL_MOUSEBUTTONDOWN: // Click de souris 
                SDL_Log("+clic");
                break;
            case SDL_MOUSEBUTTONUP: // Click de souris relâché
                SDL_Log("-clic");
                break;
            case SDL_MOUSEWHEEL: // Scroll de la molette
                if (events.wheel.y > 0)
                    SDL_Log("up %d", events.wheel.y);
                else if (events.wheel.y < 0) 
                    SDL_Log("down %d", events.wheel.y);
                break;
            case SDL_KEYUP:
                SDL_Log("-key");
                break;
            }
            
        }

        //background
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);

        

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