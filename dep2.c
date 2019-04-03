#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char *argv[])
{

SDL_Surface *screen = NULL;
    SDL_Surface *pos1=NULL,*background=NULL;
    SDL_Rect positionpos1,positionscreen;
    int continuer = 1;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    pos1=  IMG_Load("ph1.png");
    background = SDL_LoadBMP("exemple_map.bmp");
    
    positionpos1.x = 0;
    positionpos1.y =0;
    positionscreen.x = 0;
    positionscreen.y = 0;
    SDL_BlitSurface(background, NULL, screen, &positionscreen);

while (continuer)
{

SDL_PollEvent(&event);
	switch(event.type)
    {

case SDL_QUIT: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;

                    break;

}

int val=0;
while(val==0)
{
while(positionpos1.x<801 && positionpos1.x>-1)
{positionpos1.x+=10;
SDL_BlitSurface(background, NULL, screen, &positionscreen);
SDL_BlitSurface(pos1, NULL, screen, &positionpos1);
SDL_Delay(30);
 SDL_Flip(screen);
if(positionpos1.x==800)
positionpos1.x=0;}
}}
 SDL_Quit();

    return EXIT_SUCCESS;
}
