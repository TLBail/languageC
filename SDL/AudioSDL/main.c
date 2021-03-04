#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_image.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_mixer.h>


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
    //audio
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
        return -1;
    }
    //event et bouclePrincipal
    SDL_Event events;
    int isOpen = 1;


    #pragma endregion

    //chargement music
    Mix_Music* music = Mix_LoadMUS("./data/minigame-mario-luigi-bowsers-inside-story.mp3");
    if (music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        goto exit;
    }

    //initialisation des valeur
    Uint8 volume;
    volume = 128;
    Mix_PlayMusic(music, -1); // Joue notre musique 
    Mix_VolumeMusic(volume);
    
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
                if (events.key.keysym.sym == SDLK_SPACE){ // Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                    
                    if( Mix_PausedMusic() == 1 )
                        {
                            //On enlève la pause (la musique repart où elle en était)
                            Mix_ResumeMusic();
                        }
                        //Si la musique est en train de jouer
                        else
                        {
                            //On met en pause la musique
                            Mix_PauseMusic();
                        }
                }
                if (events.key.keysym.sym == SDLK_UP){
                    volume++;
                    Mix_VolumeMusic(volume);
                }
                
                if (events.key.keysym.sym == SDLK_DOWN){
                    volume--;
                    Mix_VolumeMusic(volume);
                }
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
exit:
    Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio();
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 

    #pragma endregion
}