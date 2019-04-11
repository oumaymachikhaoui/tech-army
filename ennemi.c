#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonction.h"
 

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *rectangle = NULL , *fond = NULL, *perso= NULL ;
    SDL_Rect position,posfond;

    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);

	posfond.x=0;
	posfond.y=0;

    ecran = SDL_SetVideoMode(280, 280, 32, SDL_HWSURFACE);
    // Allocation de la surface
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
	perso=IMG_Load("ennemi.png");
	

    position.x = 10; // Les coordonnées de la surface seront (0, 0)
    position.y = 0;
    // Remplissage de la surface avec du blanc
int direction=1;
	while(1)
{
move(direction,&position);
 //position.x=position.x+1;
if(position.x==50)
{
direction=2;
}
if(position.x==10)
{
direction=1;
}
SDL_Delay(50);
//SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); 
SDL_BlitSurface(fond, NULL, ecran, &posfond);
SDL_BlitSurface(perso, NULL, ecran, &position); // Collage de la surface sur l'écran
SDL_Flip(ecran); // Mise à jour de l'écran

    //pause();
}
    
int continuer=1;

while(continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer=0;
}
}
    /*pause();*/

    SDL_FreeSurface(rectangle); // Libération de la surface
    SDL_Quit();

    return EXIT_SUCCESS;
}

