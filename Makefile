prog:fonction.o main.o
	gcc fonction.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -lSDL -lSDL_image -g
