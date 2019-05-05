#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
#include "type.h"
bool collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
    if(rect1->y >= rect2->y + rect2->h)
        return 0;
    if(rect1->x >= rect2->x + rect2->w)
        return 0;
    if(rect1->y + rect1->h <= rect2->y)
        return 0;
    if(rect1->x + rect1->w <= rect2->x)
        return 0;
    return 1;
}

void anim_hero(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_hero/hero_spr_03.png");
t[1]=IMG_Load("frames_hero/hero_spr_04.png");
t[2]=IMG_Load("frames_hero/hero_spr_05.png");
t[3]=IMG_Load("frames_hero/hero_spr_06.png");

}

/*void anim_hero_attack(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_hero/hero_spr_03.png");
t[1]=IMG_Load("frames_hero/hero_spr_04.png");
t[2]=IMG_Load("frames_hero/hero_spr_05.png");
t[3]=IMG_Load("frames_hero/hero_spr_06.png");

}*/



void anim_hero_reverse(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_hero/hero_spr_08.png");
t[1]=IMG_Load("frames_hero/hero_spr_09.png");
t[2]=IMG_Load("frames_hero/hero_spr_10.png");
t[3]=IMG_Load("frames_hero/hero_spr_11.png");

}


void anim_enemy(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_enemy/ennemi_spr_02.png");
t[1]=IMG_Load("frames_enemy/ennemi_spr_03.png");
t[2]=IMG_Load("frames_enemy/ennemi_spr_04.png");
t[3]=IMG_Load("frames_enemy/ennemi_spr_05.png");

}

void anim_enemy_attack_reverse(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_enemy/ennemi_spr_11.png");
t[1]=IMG_Load("frames_enemy/ennemi_spr_12.png");
t[2]=IMG_Load("frames_enemy/ennemi_spr_13.png");
t[3]=IMG_Load("frames_enemy/ennemi_spr_14.png");

}

void anim_enemy_attack(SDL_Surface *t[])
{

t[0]=IMG_Load("frames_enemy/ennemi_spr_15.png");
t[1]=IMG_Load("frames_enemy/ennemi_spr_16.png");
t[2]=IMG_Load("frames_enemy/ennemi_spr_17.png");
t[3]=IMG_Load("frames_enemy/ennemi_spr_18.png");

}


void anim_enemy_reverse(SDL_Surface *t[])
{
t[0]=IMG_Load("frames_enemy/ennemi_spr_07.png");
t[1]=IMG_Load("frames_enemy/ennemi_spr_08.png");
t[2]=IMG_Load("frames_enemy/ennemi_spr_09.png");
t[3]=IMG_Load("frames_enemy/ennemi_spr_10.png");

}


void display(SDL_Surface *ecran,SDL_Surface *bg,SDL_Surface *img,SDL_Surface *img1,SDL_Rect pos,SDL_Rect pos1)
{

SDL_BlitSurface(bg,NULL,ecran,NULL);
SDL_BlitSurface(img,NULL,ecran,&pos);
SDL_BlitSurface(img1,NULL,ecran,&pos1);
SDL_Flip(ecran);
SDL_Delay(1000/30);
}

void AItest()
{


SDL_Surface *ecran=NULL,*bg=NULL,*game_over=NULL;
unit ue,uh;
uh.pos.x=0;
uh.pos.w=95;
uh.pos.h=96;
uh.pos.y=400;

ue.pos.x=1200;
ue.pos.y=400;
ue.pos.h=95;
ue.pos.w=100;
SDL_Event e;
int life=100;
anim_hero(uh.t);
anim_enemy_reverse(ue.t);
int i=0,j=0,done=0;
bg=SDL_LoadBMP("background.bmp");
game_over=IMG_Load("game_over.png");
ecran = SDL_SetVideoMode(1600,600, 32, SDL_HWSURFACE);
while(!done)
{
	printf("LIFE %d \n",life);
while(SDL_PollEvent(&e))
{
    if(e.type==SDL_QUIT)
    {
        done=1;
        break;

    }
}
display(ecran,bg,uh.t[i],ue.t[i],uh.pos,ue.pos);


uh.pos.x+=10;
i++;
if(i>=3)
{

	i=0;
}

/*if(uh.pos.x>=300)
{

	ue.pos.x-=10;
}*/
if(uh.pos.x>=600 && uh.pos.x<ue.pos.x)
{

ue.pos.x-=10;



}
if(collision(&uh.pos,&ue.pos))
{

	anim_enemy_attack(ue.t);
	ue.pos.x-=10;
	life-=10;
//	display(ecran,bg,uh.t[i],ue.t[i],uh.pos,ue.pos);

}
if(uh.pos.x>=ue.pos.x)
{

//anim_enemy(ue.t);
ue.pos.x+=10;
if(collision(&uh.pos,&ue.pos) && uh.pos.x>=ue.pos.x)
{
anim_enemy_attack_reverse(ue.t);
ue.pos.x-=10;
life-=5;
}

}
/*if(life<=0)
{

	SDL_BlitSurface(game_over,NULL,ecran,NULL);
	SDL_Flip(ecran);
	SDL_Delay(8000);
	break;
}*/

}



}
