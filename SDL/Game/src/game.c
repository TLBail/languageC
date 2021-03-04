#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_image.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_mixer.h>


#include <time.h>
#include <math.h>

SDL_Window* pWindow{ nullptr }; // ma fenêtre 
SDL_Renderer* pRenderer{ nullptr }; // mon rendu

#define HEIGHT 600
#define WIDTH 800
#define APPNAME "Pong"
#define VOLUME 50
#define NBPOINT 100

//chargement music
Mix_Music* music;


int init(){
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        return 1;     
    }       
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();
        return 1;    
    }           

    //transparence
    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
    //nom fenetre
    SDL_SetWindowTitle(pWindow, APPNAME);
    //audio
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    music = Mix_LoadMUS("./data/minigame-mario-luigi-bowsers-inside-story.mp3");

    //initialisation des valeur du sons
    Uint8 volume;
    volume = VOLUME;
    Mix_PlayMusic(music, -1); // Joue notre musique 
    Mix_VolumeMusic(volume);
    
    return 0;

}

void exit(){
    Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio();
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit(); 
}

int colid(SDL_Rect r1, SDL_Rect r2){
    if(r1.x + r1.w < r2.x || r1.y + r1.h < r2.y || r1.x > r2.x + r2.w || r1.y > r2.y + r2.h)
        return 0;
    return 1;

}

void GameOver(){
    SDL_Log("Game Over");
    SDL_Event event;
    int Game = 1;
    while (Game)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type) /* On teste le type d'événement */
            {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                Game = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            }
        }
    }
     Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio();
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
}

int brickVide(SDL_Rect tab[], int TAILLETAB){
    for (size_t i = 0; i < TAILLETAB; i++)
    {
        if(tab[i].w != 0) return 0;
    }
    return 1;
    
}

void win(){
    SDL_Log("Felicitations Tu a gagné");

    //initialisation des valeur
    srand(time(NULL));
    SDL_Point point[NBPOINT];
    int size = 0, x = 0, y = 0;
    SDL_Point pointe;

    SDL_Event event;
    int Game = 1;
    while (Game)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type) /* On teste le type d'événement */
            {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                Game = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            }

            //calcul des coordonné des point
            size++;
            for (size_t i = 0; i < NBPOINT; i++)
            {
                x = WIDTH / 2 + cos(rand() % 1000) * size;
                y = HEIGHT / 2 + sin(rand() % 1000) * size;
                pointe = {x , y};
                point[i] = pointe;
            }

            //background
            SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
            SDL_RenderClear(pRenderer);

            //Affichage des point
            for (size_t i = 0; i < NBPOINT; i++)
            { 
                SDL_SetRenderDrawColor(pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
                SDL_RenderDrawPoint(pRenderer, point[i].x, point[i].y);
            }
            
            //rendu final
            SDL_RenderPresent(pRenderer);

            SDL_Delay(16);

        }
    }
     Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio();
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();    
}