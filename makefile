ts:fn.o main.o
	gcc fn.o main.o -o ts -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf


fn.o:fn.c
	gcc -c fn.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
	
main.o:main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
