#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main(int argc, char *argv[])
{
	SDL_Event event;
    SDL_Surface *saved=NULL,*d1=NULL,*d2=NULL, *ecran = NULL, *imageDeFond = NULL ,*img1=NULL,*img2=NULL,*img3=NULL,*img4=NULL,*img5=NULL,*img6=NULL,*img7=NULL,*img8=NULL;
    SDL_Rect positionFond,pos,pos1,pos2,pos3,pos4,pos5,pos6,pos7,pos8;
    int continuer = 1;
    positionFond.x = 0;
    positionFond.y = 0;
    pos.x = 0;
    pos.y = 200;



    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(800, 380, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("tache 1", NULL);

imageDeFond = IMG_Load("bg.png");
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

img1 = SDL_LoadBMP("1.bmp");
SDL_SetColorKey(img1, SDL_SRCCOLORKEY, SDL_MapRGB(img1->format, 255, 255, 255));
SDL_BlitSurface(img1, NULL, ecran, &pos1);

img2 = SDL_LoadBMP("2.bmp");
SDL_SetColorKey(img2, SDL_SRCCOLORKEY, SDL_MapRGB(img2->format, 255, 255, 255));
SDL_BlitSurface(img2, NULL, ecran, &pos2);

img3 = SDL_LoadBMP("3.bmp");
SDL_SetColorKey(img3, SDL_SRCCOLORKEY, SDL_MapRGB(img3->format, 255, 255, 255));
SDL_BlitSurface(img3, NULL, ecran, &pos3);

img4 = SDL_LoadBMP("4.bmp");
SDL_SetColorKey(img4, SDL_SRCCOLORKEY, SDL_MapRGB(img4->format, 255, 255, 255));
SDL_BlitSurface(img4, NULL, ecran, &pos4);

img5 = SDL_LoadBMP("5.bmp");
SDL_SetColorKey(img5, SDL_SRCCOLORKEY, SDL_MapRGB(img5->format, 255, 255, 255));
SDL_BlitSurface(img5, NULL, ecran, &pos5);

img6 = SDL_LoadBMP("6.bmp");
SDL_SetColorKey(img6, SDL_SRCCOLORKEY, SDL_MapRGB(img6->format, 255, 255, 255));
SDL_BlitSurface(img6, NULL, ecran, &pos6);

img7 = SDL_LoadBMP("7.bmp");
SDL_SetColorKey(img7, SDL_SRCCOLORKEY, SDL_MapRGB(img7->format, 255, 255, 255));
SDL_BlitSurface(img7, NULL, ecran, &pos7);

img8 = SDL_LoadBMP("8.bmp");
SDL_SetColorKey(img8, SDL_SRCCOLORKEY, SDL_MapRGB(img8->format, 255, 255, 255));
SDL_BlitSurface(img8, NULL, ecran, &pos8);

 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 SDL_BlitSurface(img1, NULL, ecran, &pos);
 SDL_EnableKeyRepeat(100, 100);
saved=d1;
 d1=img1;
 d2=img5;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: // Flèche haut
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_BlitSurface(saved, NULL, ecran, &pos);
                        pos.y=pos.y-30;
                        break;

                    case SDLK_DOWN: // Flèche bas
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_BlitSurface(saved, NULL, ecran, &pos);
                        pos.y=pos.y+30;
                        break;

                    case SDLK_RIGHT: // Flèche droite
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_BlitSurface(d1, NULL, ecran, &pos);
                        pos.x=pos.x+30;
                        saved=d1;
                          if (d1==img1){d1=img2;}
                           else if (d1==img2){d1=img3;}
                            else if (d1==img3){d1=img4;}
                             else if (d1==img4){d1=img1;}
                        break; 

                    case SDLK_LEFT: // Flèche gauche
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_BlitSurface(d2, NULL, ecran, &pos);
                        pos.x=pos.x-30;
                        saved=d2;
                         if (d2==img5){d2=img6;}
                          else if (d2==img6){d2=img7;}
                           else if (d2==img7){d2=img8;}
                            else if (d2==img8){d2=img5;}
                        break;
                }
                break;
        }

        SDL_Flip(ecran);
    }


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }

    SDL_FreeSurface(imageDeFond);
    SDL_Quit();


}


