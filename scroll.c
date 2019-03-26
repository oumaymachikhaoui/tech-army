#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

int main(int argc, char const *argv[])
{

    SDL_Surface *screen;
	SDL_Surface *background;
	SDL_Rect positionecran;
	SDL_Rect positionbackground;
	SDL_Event e;
	int continuer=1;
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s\n",Mix_GetError());
	}
	Mix_Music *music;
	music = Mix_LoadMUS("imgsound/play/gladiator.mp3");
	Mix_PlayMusic(music,1);

	SDL_Init(SDL_INIT_EVERYTHING);
	screen= SDL_SetVideoMode(1366,384,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	background=IMG_Load("imgsound/play/map.bmp");
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
                   break;
                   case SDLK_a:
                   camera.x-=10;
                   break;
		    	 }
		    	 break;
		    }
		}
		}
	}
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_Quit();

	return 0;
}