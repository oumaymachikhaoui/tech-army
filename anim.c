#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "anim.h"

int anim(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Surface *pos1=NULL,*pos2=NULL,*background=NULL;
    SDL_Rect positionpos1,positionpos2,positionscreen;
    int continuer = 1;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    pos1=  IMG_Load("ph1.png");
    pos2 = IMG_Load("ph2.png");
    background = SDL_LoadBMP("exemple_map.bmp");
    
    positionpos1.x =350;
    positionpos1.y =200;
    positionpos2.x = 350;
    positionpos2.y =200;
    positionscreen.x =0;
    positionscreen.y =0;
    SDL_BlitSurface(background, NULL, screen, &positionscreen);

while (continuer)
{

while(SDL_PollEvent(&event))
{
	switch(event.type)
    {

case SDL_QUIT: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;

                    break;

}
 	
}

 
SDL_BlitSurface(background, NULL, screen, &positionscreen);
SDL_BlitSurface(pos1, NULL, screen, &positionpos1);
    SDL_Delay(800);
SDL_Flip(screen);


 
    SDL_BlitSurface(background, NULL, screen, &positionscreen);
    SDL_BlitSurface(pos2, NULL, screen, &positionpos2);
    SDL_Delay(800);
SDL_Flip(screen);

 
    
}        	



  SDL_Quit();

    return EXIT_SUCCESS;
}

