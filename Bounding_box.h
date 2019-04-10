#include "SDL/SDL.h"

typedef struct Player
{
int id;

SDL_Rect anim[10];
SDL_Rect PosPlayer;
int vie;
int score;
}Player;


typedef struct Map
{
char Path[50];
SDL_Rect Obsacles[100];
SDL_Rect Secondary[200];
}Map;


typedef struct Enigme
{
char* Nom;
char* Descreption;
char* Solution;
SDL_Rect pos;
int tSol;
}Enigme;

Enigme init_enigmes(Enigme e[]);

int collision(SDL_Rect* rect1,SDL_Rect* rect2);


