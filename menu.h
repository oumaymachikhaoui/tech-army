#ifndef MENU_H
#define MENU_H

int menu(SDL_Surface *screen,int sound);
int play(SDL_Surface *screen , int *music ,int *sound);
void options(SDL_Surface *screen,int *music,int *sound);
void credits (SDL_Surface *screen);

#endif