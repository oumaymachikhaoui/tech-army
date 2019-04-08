#include <stdlib.h>
#include <stdio.h>
#include<string.h>
//SDL libs
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Bounding_box.h"




 
int width = 640;
int height = 480;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
        SDL_Surface *screen;
        int running = 1;
        screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
        
        const int FPS = 30;
        Uint32 start;
        int b[4] = {0,0,0,0};
        SDL_Rect rect;
        rect.x = 10;
        rect.y = 10;
        rect.w = 20;
        rect.h = 20;
        SDL_Rect recarr[5];
        recarr[0].x=70;
        recarr[0].y=0;
        recarr[0].h=200;
        recarr[0].w=10;
 
        recarr[1].x=300;
        recarr[1].y=200;
        recarr[1].h=20;
        recarr[1].w=80;
 
        recarr[2].x=200;
        recarr[2].y=100;
        recarr[2].h=100;
        recarr[2].w=10;
 
        recarr[3].x=40;
        recarr[3].y=300;
        recarr[3].h=20;
        recarr[3].w=60;
 
        recarr[4].x=100;
        recarr[4].y=0;
        recarr[4].h=200;
        recarr[4].w=10;
 

        Uint32 color2 = SDL_MapRGB(screen->format, 0xff,0xff,0xff);
        Uint32 color = SDL_MapRGB(screen->format, 0,0,0);
        for(int i = 0; i < 5; i += 1) 
        {
                        SDL_FillRect(screen,&recarr[i],color2);
        }



SDL_Rect temp,t;

        while(running)
        {
            start = SDL_GetTicks();
            SDL_PollEvent(&event);
                    switch(event.type)
                    {
                        case SDL_QUIT:
                            running=0;
                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym) 
                                        {
                                                case SDLK_UP:
                                                        b[0] = 1;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 1;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 1;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 1;
                                                        break;
                                        }
                                    break;

                                    case SDL_KEYUP:
                                
                                        switch(event.key.keysym.sym) 
                                        {
                                                case SDLK_UP:
                                                        b[0] = 0;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 0;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 0;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 0;
                                                        break;
                                       
                                        }
                                        break;
                    }

                SDL_FillRect(screen, &rect, color);

                 if(b[0]) {
                        rect.y-=5;
                        for(int i = 0; i < 5; i += 1)
                                if(collision(&rect,&recarr[i]))
                                        rect.y+=5;
                }
                if(b[1]) {
                        rect.x-=5;
                        for(int i = 0; i < 5; i += 1)
                                if(collision(&rect,&recarr[i]))
                                        rect.x+=5;
                }
                if(b[2]) {
                        rect.y+=5;
                        for(int i = 0; i < 5; i += 1)
                                if(collision(&rect,&recarr[i]))
                                        rect.y-=5;
                }
                if(b[3]) {
                        rect.x+=5;
                        for(int i = 0; i < 5; i += 1)
                                if(collision(&rect,&recarr[i]))
                                        rect.x-=5;
                }

                if(rect.x<0)
                {rect.x=0;}
                 if(rect.y<0)
                {rect.y=0;}



        temp=recarr[0];


 






        
          
                 
               

        
                
        





                

         
         SDL_FillRect(screen, &rect, color2);
                SDL_Flip(screen);

     

             
         if(recarr[0].y<100)
        {
                
                recarr[0].y+=5;
                SDL_FillRect(screen,&recarr[0],color2);
                
                SDL_Flip(screen);
                SDL_FillRect(screen,&recarr[0],color);    
        }
                
         if(recarr[0].y>=100)
        {
                recarr[0].y=0;
                SDL_FillRect(screen,&recarr[0],color2);
                
                SDL_Flip(screen);
                
                SDL_FillRect(screen,&recarr[0],color);
        } 




if(1000/FPS > SDL_GetTicks()-start) 
                {
                                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }   

        }


       SDL_Quit();



    return 0;

}
