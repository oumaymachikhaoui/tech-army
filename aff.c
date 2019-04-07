#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "aff.h"

int aff(int argc, char *argv[])
{SDL_Surface *screen = NULL;
    SDL_Surface *pos1=NULL,*background=NULL;
    SDL_Rect positionpos1,positionscreen;
    int continuer = 1;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    pos1=  IMG_Load("1.png");
    background = SDL_LoadBMP("exemple_map.bmp");
    
    positionpos1.x = 300;
    positionpos1.y =150;
    positionscreen.x = 0;
    positionscreen.y = 0;
while(continuer)
{SDL_BlitSurface(background, NULL, screen, &positionscreen);
SDL_BlitSurface(pos1, NULL, screen, &positionpos1);
SDL_Flip(screen);}
return EXIT_SUCCESS;
}

