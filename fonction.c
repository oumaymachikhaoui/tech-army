#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"

void setrects_right(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=191.25;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=191.25;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=191.25;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=191.25;
clip[3].w=113.75;
clip[3].h=191.2;

clip[4].x=455;
clip[4].y=191.25;
clip[4].w=113.75;
clip[4].h=191.2;

clip[5].x=568.75;
clip[5].y=191.25;
clip[5].w=113.75;
clip[5].h=191.2;


}

void setrects_left(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=382.5;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=382.5;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=382.5;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=382.5;
clip[3].w=113.75;
clip[3].h=191.2;

clip[4].x=455;
clip[4].y=382.5;
clip[4].w=113.75;
clip[4].h=191.2;

clip[5].x=568.75;
clip[5].y=382.5;
clip[5].w=113.75;
clip[5].h=191.2;

}
void scrollingleft(SDL_Rect *camera)
     {

	camera->x=0;
	camera->y=0;
	camera->w=1366;
	camera->h=384;
  

camera->x-=10;
                    while(camera->x<0)
                   {
                   	camera->x+=10;
                   }



}
void scrollingright( SDL_Rect *camera)
     {

	camera->x=0;
	camera->y=0;
	camera->w=1366;
	camera->h=384;
  

camera->x+=10;
                   while(camera->x>6000)
                   {
                   	camera->x-=10;
                   }

}
     
void scrollingleft2(SDL_Rect *camera2)
     {

	camera2->x=0;
	camera2->y=0;
	camera2->w=1366;
	camera2->h=384;
  
camera2->x-=10;
                    while(camera2->x<0)
                   {
                   	camera2->x+=10;
                   }




}
void scrollingright2(SDL_Rect *camera2)
     {
	camera2->x=0;
	camera2->y=0;
	camera2->w=1366;
	camera2->h=384;
  

  

camera2->x+=50;
                   while(camera2->x>6000)
                   {
                   	camera2->x-=50;
                   }

}


void animation(acteur *acteur,SDL_Rect camera,SDL_Rect camera2)
{
int tempsPrecedent = 0, tempsActuel = 0;
char temps[20];
//int keysHeld[323]={0};
SDL_Rect back1,back2;
SDL_Init(SDL_INIT_VIDEO);
acteur->screen=SDL_SetVideoMode(1366,768,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
acteur->background1=IMG_Load( "map1.png" );
acteur->background2=IMG_Load( "map2.png" ); 
acteur->frame=0;
acteur->frame2=0;
acteur->running=1;
acteur->image=IMG_Load("image1.png");
acteur->image2=IMG_Load("image2.png");
acteur->rect.x=0;		
acteur->rect.y=477;

acteur->rect2.x=0;
acteur->rect2.y=120;

back1.x=0;
back1.y=0;


back2.x=0;
back2.y=355;



//SDL_FillRect(acteur->screen,&acteur->screen->clip_rect,0x00);
//SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
/*SDL_BlitSurface ( acteur->background1 ,  &camera1 ,  acteur->screen ,  &back1); 
SDL_Flip(acteur->screen);
SDL_BlitSurface ( acteur->background2 ,  &camera2 ,  acteur->screen , &back2); 
SDL_Flip(acteur->screen);*/
SDL_BlitSurface ( acteur->background1 ,  &camera ,  acteur->screen ,&back1);
SDL_Flip(acteur->screen);
SDL_BlitSurface ( acteur->background2 ,  &camera2 ,  acteur->screen ,&back2); 
SDL_Flip(acteur->screen);
SDL_BlitSurface(acteur->image,&acteur->rects[0],acteur->screen,&acteur->rect);
SDL_BlitSurface(acteur->image2,&acteur->rects2[0],acteur->screen,&acteur->rect2);
//SDL_Flip(acteur->screen);
SDL_EnableKeyRepeat(100,100);
while (acteur->running)
    {


SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));

SDL_BlitSurface ( acteur->background1 ,  &camera ,  acteur->screen ,&back1); 
SDL_BlitSurface ( acteur->background2 ,  &camera2 ,  acteur->screen ,&back2);


SDL_BlitSurface(acteur->image,&acteur->rects[acteur->frame],acteur->screen,&acteur->rect);
SDL_BlitSurface(acteur->image2,&acteur->rects2[acteur->frame2],acteur->screen,&acteur->rect2);

mini(*acteur);
SDL_Flip(acteur->screen);
      SDL_WaitEvent(&acteur->event);
        switch(acteur->event.type)
        {
            case SDL_QUIT:
                acteur->running = 0;
                break;
            case SDL_KEYDOWN:
                switch(acteur->event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite


tempsActuel = SDL_GetTicks();
if(tempsActuel - tempsPrecedent >100){
if(acteur->rect.x<=1270)
{   
 scrollingright2(&camera2);
                        acteur->rect.x=10+acteur->rect.x;}
else acteur->rect.x-=10;
//mini(*acteur);

setrects_right(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}	
tempsPrecedent = tempsActuel;
}	
                        break;
                    case SDLK_LEFT: // Flèche gauche

tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){  

    scrollingleft2(&camera2) ;                 
acteur->rect.x=-10+acteur->rect.x;
//mini(*acteur);
 //scrollingleft(&(acteur->rect) , &camera1) ;



setrects_left(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}
tempsPrecedent = tempsActuel;
}


                        break;



 case SDLK_d: // Flèche droite

tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){

if(acteur->rect2.x<=1270)
{ scrollingright(&camera) ;
                        acteur->rect2.x=10+acteur->rect2.x;}
else acteur->rect2.x-=10;
//mini(*acteur);

setrects_right(acteur->rects2);
acteur->frame2++;
if(acteur->frame2==5){
acteur->frame2=0;
}	
tempsPrecedent = tempsActuel;
}	
                        break;
                    case SDLK_q: // Flèche gauche

tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){

 scrollingleft(&camera) ;
                        acteur->rect2.x=-10+acteur->rect2.x;




setrects_left(acteur->rects2);
acteur->frame2++;
if(acteur->frame2==5){
acteur->frame2=0;
}
tempsPrecedent = tempsActuel;
}


                        break;
                }
                break;
        }
}


}



void mini(acteur acteur)
{SDL_Surface *imageDeFond = NULL ,*img1=NULL,*img2=NULL;
    SDL_Rect positionFond,pos1,pos2;
    int continuer = 1;
    positionFond.x = 0;
    positionFond.y = 298;
    pos1.x = 0;
    pos1.y = 346;
    pos2.y = 347;
img1=  IMG_Load("1.png");
img2=  IMG_Load("2.png");

    SDL_Init(SDL_INIT_VIDEO);
imageDeFond = IMG_Load("map.png");
SDL_BlitSurface(imageDeFond, NULL, acteur.screen, &positionFond);
SDL_BlitSurface (img1,NULL,  acteur.screen ,&pos1);
SDL_BlitSurface (img2,NULL,  acteur.screen ,&pos2);
SDL_Flip(acteur.screen);
pos1.x=acteur.rect.x/5;
pos2.x=acteur.rect2.x/5;
SDL_BlitSurface(imageDeFond, NULL, acteur.screen, &positionFond);
if(pos1.x<=385)
{
SDL_BlitSurface (img1,NULL,  acteur.screen ,&pos1);

SDL_Flip(acteur.screen);

}
if(pos2.x<=385)
{
SDL_BlitSurface (img2,NULL,  acteur.screen ,&pos2);
SDL_Flip(acteur.screen);

}
}


