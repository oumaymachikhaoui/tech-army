#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct  {
SDL_Surface *screen,*image,*background1,*image2,*background2;
SDL_Event event ;
SDL_Rect rect ,rect2 ;
int running;
int frame,frame2;
//SDL_Rect camera1,back1,camera2,back2;
SDL_Rect rects[6],rects2[6];
}acteur;

void setrects_right(SDL_Rect clip[]);
void setrects_left(SDL_Rect clip[]);
void scrollingleft(SDL_Rect *camera);
void scrollingright(SDL_Rect *camera);
void scrollingleft2(SDL_Rect *camera2);
void scrollingright2(SDL_Rect *camera2);
void animation(acteur *acteur,SDL_Rect camera,SDL_Rect camera2);
void mini(acteur acteur);

#endif
