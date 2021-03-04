#include <stdlib.h>
#include <stdio.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_image.h>
#include <C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include\SDL2\SDL_mixer.h>


#include <time.h>
#include <math.h>
#include "src/game.h"

#define HEIGHT 600
#define WIDTH 800

//parametre Bar
#define SPEED 25
#define BARSIZEW 100
#define BARSIZEH 30

//parametre balle
#define BALLESIZE 10
#define VITESSEBALLE 4

//parametre Brick
#define NOMBREBRICKWIDTH 0
#define BRICKWIDTH 100
#define BRICKHEIGHT 30



int main(int argc, char* argv[]) 
{     

    if(init()) return EXIT_FAILURE;


    //event et bouclePrincipal
    SDL_Event events;
    int isOpen = 1;


    //Bar
    SDL_Point positionBar{WIDTH / 2 - 50, HEIGHT - HEIGHT / 4};
    SDL_Rect bar{positionBar.x, positionBar.y, 100, 30};

    //balle
    SDL_Rect balle{10, 10, BALLESIZE, BALLESIZE};
    int velociterx = VITESSEBALLE , velocitery = VITESSEBALLE;

    //brick
    SDL_Rect brick1 [NOMBREBRICKWIDTH];
    SDL_Rect brick2 [NOMBREBRICKWIDTH];
    SDL_Rect brick3 [NOMBREBRICKWIDTH];
    
    for (int i = 0; i < NOMBREBRICKWIDTH; i++)
    {
            SDL_Rect tmp{100 + i * (BRICKWIDTH + BRICKWIDTH / 5), BRICKHEIGHT * 2, BRICKWIDTH, BRICKHEIGHT};
            brick1[i] = tmp;
            SDL_Rect tmp2{100 + i * (BRICKWIDTH + BRICKWIDTH / 5), BRICKHEIGHT * 4, BRICKWIDTH, BRICKHEIGHT};
            brick2[i] = tmp2;
            SDL_Rect tmp3{100 + i * (BRICKWIDTH + BRICKWIDTH / 5), BRICKHEIGHT * 6, BRICKWIDTH, BRICKHEIGHT};
            brick3[i] = tmp3;        
    }
    


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
                    
                    
                }
                if (events.key.keysym.sym == SDLK_LEFT){
                    if(positionBar.x > 0){
                          positionBar.x -= SPEED;
                    } else{
                        positionBar.x = 0;
                    }
                      
                }
                
                if (events.key.keysym.sym == SDLK_RIGHT){
                   if(positionBar.x < (WIDTH - BARSIZEW)){
                          positionBar.x += SPEED;
                    } else{
                        positionBar.x = WIDTH - BARSIZEW;
                    }
                    
                }
                break;
            }
        }

        //actualisation des valeur de la bar
        bar.x = positionBar.x;
        bar.y = positionBar.y;

        //on bouge la balle
        balle.x += velociterx;
        balle.y += velocitery;

        //on verifie que la balle touche rien
        if(balle.x < 0 || balle.x > WIDTH - BALLESIZE) velociterx = -velociterx;
        if(balle.y < 0 ) velocitery = -velocitery;
        if(balle.y > HEIGHT - BALLESIZE){
            GameOver();
            return EXIT_SUCCESS; 
        } 
        if(colid(bar, balle)) velocitery = -velocitery;
        for (size_t i = 0; i < NOMBREBRICKWIDTH; i++)
        {
            if(brick1[i].w != 0 && colid(balle, brick1[i])){
                velocitery = -velocitery;
                brick1[i].w = 0;
            }
            if(brick2[i].w != 0 && colid(balle, brick2[i])){
                velocitery = -velocitery;
                brick2[i].w = 0;
            }
            if(brick3[i].w != 0 && colid(balle, brick3[i])){
                velocitery = -velocitery;
                brick3[i].w = 0;
            }
        }
        
        //on verifie si le joueur a cassé toutes les briques
        if(brickVide(brick1, NOMBREBRICKWIDTH) && brickVide(brick2, NOMBREBRICKWIDTH) && brickVide(brick3, NOMBREBRICKWIDTH)){
            win();
            return EXIT_SUCCESS;
        }

        //background
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);

        //affichage de la bar de jeu
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(pRenderer, &bar);

        //affichage de la balle 
        SDL_RenderFillRect(pRenderer, &balle);
       
        //affichage des Brick
        SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
        SDL_RenderFillRects(pRenderer, brick1, NOMBREBRICKWIDTH);
        SDL_RenderFillRects(pRenderer, brick2, NOMBREBRICKWIDTH);
        SDL_RenderFillRects(pRenderer, brick3, NOMBREBRICKWIDTH);
        


        //rendu final
        SDL_RenderPresent(pRenderer);

        SDL_Delay(16);

    }



    exit();
    return EXIT_SUCCESS;
}