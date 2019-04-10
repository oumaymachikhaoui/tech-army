
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
    int status;/*!<entier*/
    float x,y;/*!<reel*/
    float vx,vy;/*!<reel*/
    SDL_Surface *S;
    SDL_Rect pos;
    SDL_Surface *screen;
    SDL_Surface *tsawer[4];
    SDL_Surface *tsawerL[4];
    SDL_Surface *imin1;
    SDL_Surface *imin2;
    SDL_Surface *imin3;
    SDL_Surface *imin4;

    // anim à gauche:
    SDL_Surface *issar1;
    SDL_Surface *issar2;
    SDL_Surface *issar3;
    SDL_Surface *issar4;
} Sprite;

void InitSprite(Sprite* Sp)
{
    Sp->pos.x = 150.0f;
    Sp->pos.y = 250.0f;
    Sp->status = STAT_SOL;
    Sp->vx = Sp->vy = 0.0f;
}

void Render(Sprite* Sp)
{
    
  
    Sp->pos.x = (Sint16)Sp->x;
    Sp->pos.y = (Sint16)Sp->y;
    //Sp->S->w = 72;
    //Sp->S->h = 144;
   // SDL_FillRect(Sp->screen,SDL_MapRGB(Sp->screen->format,255,0,0));
    
}

void Saute(Sprite* Sp,float impulsion)
{
    Sp->vy = -impulsion;
    Sp->status = STAT_AIR;
}

void ControleSol(Sprite* Sp)
{
    if (Sp->y>250.0f)
    {
        Sp->y = 250.0f;
        if (Sp->vy>0)
            Sp->vy = 0.0f;
        Sp->status = STAT_SOL;
    }
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    Sp->vy += factgravite;
}

void Evolue(Sprite* Sp,Uint8* keys)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 0.5f;
    float maxhspeed = 3.0f;
    float adherance = 1.5f;
    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
// controle lateral
    if (Sp->status == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT]) // (*1)
        Sp->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        Sp->vx+=lateralspeed;
    if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        Sp->vx/=adherance;
// limite vitesse
    if (Sp->vx>maxhspeed) // (*4)
        Sp->vx = maxhspeed;
    if (Sp->vx<-maxhspeed)
        Sp->vx = -maxhspeed;
// saut
    if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)
        Saute(Sp,impulsion);
    Gravite(Sp,factgravite,factsautmaintenu,keys);
    ControleSol(Sp);
// application du vecteur à la position.
    Sp->x +=Sp->vx;
    Sp->y +=Sp->vy;
}

int main(int argc,char** argv)
{
    int i;   
    int numkeys;
    SDL_Rect positionbackground;
    SDL_Surface *background = NULL;
    Uint8 * keys;
    Sprite S;
    Uint32 timer,elapsed;
    SDL_Init(SDL_INIT_VIDEO);
    S.screen=SDL_SetVideoMode(900,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    //S.S=IMG_Load("detective.png");



    background = IMG_Load("background.png");

    S.issar1 = NULL;
    S.issar2 = NULL;
    S.issar3 = NULL;
    S.issar4 = NULL;


    S.imin1=IMG_Load("imin1.png");
    S.imin2=IMG_Load("imin2.png");
    S.imin3=IMG_Load("imin3.png");
    S.imin4=IMG_Load("imin4.png");

    S.issar1 = IMG_Load("isar1.png");
    S.issar2 = IMG_Load("isar2.png");
    S.issar3 = IMG_Load("isar3.png");
    S.issar4 = IMG_Load("isar4.png");

    S.tsawer[0]=S.imin1;
    S.tsawer[1]=S.imin2;
    S.tsawer[2]=S.imin3;
    S.tsawer[3]=S.imin4;

    S.tsawerL[0]=NULL;
    S.tsawerL[1]=NULL;
    S.tsawerL[2]=NULL;
    S.tsawerL[3]=NULL;

    S.tsawerL[0]=S.issar1;
    S.tsawerL[1]=S.issar2;
    S.tsawerL[2]=S.issar3;
    S.tsawerL[3]=S.issar4;

    positionbackground.x=0;
    positionbackground.y=0;

    SDL_BlitSurface(background, NULL, S.screen, &positionbackground);
    SDL_Flip(S.screen);

    InitSprite(&S);
    do 
    {
        timer = SDL_GetTicks();
       // SDL_FillRect(S.screen,NULL,0);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
        Evolue(&S,keys);
        if(keys[SDLK_RIGHT])
{
        i++;
        if(i==3)
            {
                i=0;
            }
        SDL_BlitSurface(background, NULL, S.screen, &positionbackground);
        SDL_BlitSurface(S.tsawer[i], NULL, S.screen, &S.pos);
        SDL_Flip(S.screen);
        
        Render(&S);
        SDL_Flip(S.screen);
    }
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<30)
            SDL_Delay(30-elapsed);

    } while (!keys[SDLK_ESCAPE]);

    //SDL_BlitSurface(background, NULL, S.screen, &positionbackground);
    //SDL_BlitSurface(S.S, NULL, S.screen, &S.pos);

    SDL_Flip(S.screen);
    SDL_FreeSurface(background);
    SDL_Quit();
    return 0;
}
