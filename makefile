menu: main.o menu.o
	gcc main.o menu.o -o game -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c
menu.o:menu.c
	gcc -c menu.c
clear:
	rm *.o
clearexec:
	rm *.o game