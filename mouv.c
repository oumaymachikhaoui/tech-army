#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

int main()
{
	SDL_Surface *screen;
	SDL_Surface *image;
	SDL_Surface *background;
	SDL_Rect positionecran;
	SDL_Rect positionbackground;
	SDL_Event e;
	int continuer=1 ,x ,y ,sens=0;
	/*if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNEL,1024)==-1)
	{
		printf("%s\n",Mix_GetError());
	}
	Mix_music *music;
	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,1);*/
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("Unable to set video mode%s\n",SDL_GetError());
		return 1;
	}

	image = IMG_Load("boy.png");
	positionecran.x = 10;
	positionecran.y = 150;
	background=IMG_Load("background.bmp");
	positionbackground.x = 0;
	positionbackground.y = 0;
	positionbackground.w=1300;
	positionbackground.h=288;
	while(continuer)
	{
		   if (x>positionecran.x+50 && sens==1)
            {
            	positionecran.x+=2;
        	}
        	else
           {
        	if (x<positionecran.x+45 && sens==2)
        	{
        		positionecran.x-=2;
        	}
        }

		SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,100,255));
		SDL_BlitSurface(background,NULL,screen,&positionbackground);
		SDL_BlitSurface(image,NULL,screen,&positionecran);
		SDL_Flip(screen);
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
		{	
			case SDL_QUIT:
		    continuer=0;
		    break;

            case SDL_MOUSEBUTTONUP:

            SDL_GetMouseState(&x,&y);
            if (x>positionecran.x)
            	sens=1;
            else
            	sens=2;
        	break;
    	}
		}
	}
	//Mix_FreeMusic(music);
	SDL_FreeSurface(image);
	//Mix_CloseAudio();
	SDL_Quit();
return 0 ;
}