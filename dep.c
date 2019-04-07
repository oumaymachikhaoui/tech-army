#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "dep.h"

int dep(int argc, char *argv[])
{

SDL_Surface *screen = NULL;
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

int i=0;
int val=0;
while(val==0)
{
while(positionpos1.y<151 && positionpos1.y>-1 && i==0)
{positionpos1.y-=10;
SDL_BlitSurface(background, NULL, screen, &positionscreen);
SDL_BlitSurface(pos1, NULL, screen, &positionpos1);
SDL_Delay(400);
 SDL_Flip(screen);
if(positionpos1.y==0 && i==0)
i=1;}
while(i==1 && positionpos1.y<151 && positionpos1.y>-1)
{positionpos1.y+=10;
SDL_BlitSurface(background, NULL, screen, &positionscreen);
SDL_BlitSurface(pos1, NULL, screen, &positionpos1);
SDL_Delay(400);
 SDL_Flip(screen);
if(positionpos1.y==150 && i==1)
i=0;}
}}
 SDL_Quit();

    return EXIT_SUCCESS;
}
