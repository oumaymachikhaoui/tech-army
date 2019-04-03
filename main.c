#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main()
{
	SDL_Surface *screen = NULL;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(1366,768,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gladiator", NULL);
	int choix, sound=1, music=1 , p ;
	 Mix_Music* backgroundSound = NULL ;
		backgroundSound = Mix_LoadMUS("../imgsound/music_menu.mp3");
		//Mix_VolumeMusic(100);
		 Mix_PlayMusic(backgroundSound,-1);

	do
	{
		choix=menu(screen,sound);
		switch(choix)
		{
			case 1:
			p=play(screen,&music,&sound);
			break;
			case 2:
			options(screen,&music,&sound);
			break;
			case 3:
			credits(screen);
			break;
		}
	}
	while(choix!=4);


	SDL_Quit();

	Mix_FreeMusic(backgroundSound);
	Mix_CloseAudio();
	return 0;
}
























































/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~B!G$h@rk[TN]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                                 ,-
                               ,'::|
                              /::::|
                            ,'::::o\                                      _..
         ____........-------,..::?88b                                  ,-' /
 _.--"""". . . .      .   .  .  .  ""`-._                           ,-' .;'
<. - :::::o......  ...   . . .. . .  .  .""--._                  ,-'. .;'
 `-._  ` `":`:`:`::||||:::::::::::::::::.:. .  ""--._ ,'|     ,-'.  .;'
     """_=--       //'doo.. ````:`:`::::::::::.:.:.:. .`-`._-'.   .;'
         ""--.__     P(       \               ` ``:`:``:::: .   .;'
                "\""--.:-.     `.                             .:/
                  \. /    `-._   `.""-----.,-..::(--"".\""`.  `:\
                   `P         `-._ \          `-:\          `. `:\
                                   ""            "            `-._) 



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Be Water My Friend~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/