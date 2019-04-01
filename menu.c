#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int menu(SDL_Surface *screen,int sound)
{
	  SDL_Surface *background[4] ;
	  SDL_Rect positionFond;



    positionFond.x = 0;
    positionFond.y = 0;
    int continuer = 1, x, y,s=0,i;
    SDL_Event event;
    Mix_Chunk* button;
    int choix=1;


    background[0]=IMG_Load("../imgsound/play.png");
    background[1]=IMG_Load("../imgsound/options.png");
    background[2]=IMG_Load("../imgsound/credits.png");
    background[3]=IMG_Load("../imgsound/exit.png");

    button = Mix_LoadWAV("../imgsound/button.wav");


     /*TTF_Init();
          SDL_Surface *text;
          SDL_Rect positiontext;
          positiontext.x=1150;
          positiontext.y=700;
      TTF_Font *police =NULL;
      SDL_Color bleu={0,0,255};
      police=TTF_OpenFont("../imgsound/ShadowsIntoLight.ttf",20);
      TTF_SetFontStyle(police,TTF_STYLE_ITALIC);
      text=TTF_RenderText_Blended(police,"~Tech Army~",bleu);*/
    

    while (continuer==1)
{

    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

        SDL_BlitSurface(background[choix-1],NULL,screen,&positionFond);
          //SDL_BlitSurface(text,NULL,screen,&positiontext);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
    {
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
           case SDLK_DOWN:
           if (sound)
            Mix_PlayChannel(1,button,0);
            if (choix==4)
                choix=1;
            else
                choix++;
            break;
            case SDLK_UP:
            if (sound)
            Mix_PlayChannel(1,button,0);
            if (choix==1)
                choix=4;
            else
                choix--;
            break;
            case SDLK_RETURN:
            continuer=0;
            break;
        }
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&x,&y);
            if (y>250 && y<346 && x>183 && x<340)
            {
                choix=1;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else if (y>373 && y<460 && x>121 && x<396)
            {
                choix=2;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
             else if (y>508 && y<588 && x>140 && x<380)
            {
                choix=3;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
             else if (y>622 && y<703 && x>180 && x<339)
            {
                choix=4;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else
            {
                s=0;
            }
            break;
            case SDL_MOUSEBUTTONUP:
        continuer=0;
        break;
    }
    }
    }


  for(i=0;i<4;i++)
  {
    SDL_FreeSurface(background[i]);
  }
    Mix_FreeChunk(button);
        /*TTF_Quit();
    TTF_CloseFont(police);
    SDL_FreeSurface(text);*/

    return choix;
}

int play(SDL_Surface *screen , int *music ,int *sound)
{
    //SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Rect positionecran;
    SDL_Rect positionbackground;
    SDL_Event e;
    int continuer=1;
   
        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
        Mix_Music* musique=NULL;
        musique = Mix_LoadMUS("../imgsound/play/gladiator.mp3");

         if ((*music)&&(*sound))
    {
        music=0;
        Mix_PlayMusic(musique,1);
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    //screen= SDL_SetVideoMode(1366,384,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    background=IMG_Load("../imgsound/play/exemple_map.bmp");
    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.w=1366;
    camera.h=384;
    SDL_EnableKeyRepeat(1,30);
    while(continuer==1)
    {
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,100,255));
        SDL_BlitSurface(background,&camera,screen,NULL);
        SDL_Flip(screen);
        while (SDL_PollEvent(&e))
        {
            switch(e.type)
        {   
            case SDL_QUIT :
            continuer=0;
            break;
            case SDL_KEYDOWN :
            {
                switch(e.key.keysym.sym)
                 {
                   case SDLK_d:
                   camera.x+=10;
                   if (camera.x>8600)
                   {
                    camera.x-=10;
                   }
                   break;
                   case SDLK_a:
                   camera.x-=10;
                    if (camera.x<0)
                   {
                    camera.x+=10;
                   }
                   break;
                 }
                 break;
            }
        }
        }
    }
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

void options(SDL_Surface *screen,int *music,int *sound)
{
    SDL_Event event;
    char chemin[100];
    int continuer=1, choix=1, i, j ,x ,y ,s=0;
        Mix_Chunk* button;
    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=0;
    SDL_Surface *background, *bouton[3][4];
    background=IMG_Load("../imgsound/options/background.png");
    button = Mix_LoadWAV("../imgsound/button.wav");
    for (i=0;i<3;i++)
    {
        for (j=0;j<4;j++)
        {
            if (i==2&&j>1)
                bouton[i][j]=NULL;
            else
            {
                sprintf(chemin,"../imgsound/options/%d%d.png", i+1, j+1);
                bouton[i][j]=IMG_Load(chemin);
            }
        }
    }
    while(continuer)
    {
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
        SDL_BlitSurface(background,NULL,screen,&positionFond);
        if (choix==1)
            SDL_BlitSurface(bouton[0][*music],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[0][*music+2],NULL,screen,&positionFond);
        if (choix==2)
            SDL_BlitSurface(bouton[1][*sound],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[1][*sound+2],NULL,screen,&positionFond);
        if (choix==3)
            SDL_BlitSurface(bouton[2][1],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[2][0],NULL,screen,&positionFond);
        SDL_Flip(screen);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                    if (*sound)
            Mix_PlayChannel(1,button,0);
                    if (choix==3)
                        choix=1;
                    else
                        choix++;
                    break;
                    case SDLK_UP:
                    if (*sound)
            Mix_PlayChannel(1,button,0);
                    if (choix==1)
                        choix=3;
                    else
                        choix--;
                    break;
                    case SDLK_RETURN:
                    switch (choix)
                    {
                        case 1:
                        if (*music)
                        {
                            Mix_PauseMusic();
                            (*music)=0;
                        }
                        else
                        {
                            Mix_ResumeMusic();
                            (*music)=1;
                        }
                        break;
                        case 2:
                        if (*sound)
                            (*sound)=0;
                        else
                            (*sound)=1;
                        break;
                        case 3:
                        continuer=0;
                        break;
                    }
                    break;
                }
                break;
                case SDL_MOUSEMOTION:
             SDL_GetMouseState(&x,&y);
            if (y>286&& y<333 && x>140 && x<385)
            {
                choix=1;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else if (y>468 && y<513 && x>140 && x<385)
            {
                choix=2;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
             else if (y>657 && y<693 && x>205 && x<312)
            {
                choix=3;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else
            {
                s=0;
            }
            break;
            case SDL_MOUSEBUTTONUP:
            switch (choix)
                    {
                        case 1:
                        if (*music)
                        {
                            Mix_PauseMusic();
                            (*music)=0;
                        }
                        else
                        {
                            Mix_ResumeMusic();
                            (*music)=1;
                        }
                        break;
                        case 2:
                        if (*sound)
                            (*sound)=0;
                        else
                            (*sound)=1;
                        break;
                        case 3:
                        continuer=0;
                        break;
                    }
               break;
            }
        }
    }


    Mix_FreeChunk(button);
    SDL_FreeSurface(background);
    for (i=0;i<3;i++)
    {
        for (j=0;j<4;j++)
        {
            if (bouton[i][j]!=NULL)
                SDL_FreeSurface(bouton[i][j]);
        }
    }
}


void credits (SDL_Surface *screen)
{
    SDL_Surface *background;
    SDL_Rect pos;
    pos.x=0;
    pos.y=0;
    SDL_Event event;
    int continuer=1;
    background=IMG_Load("../imgsound/credits/credits.png");
    SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_Flip(screen);
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_RETURN)
                continuer=0;
            break;
        }
    }
    SDL_FreeSurface(background);
}