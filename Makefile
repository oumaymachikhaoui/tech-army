prog:obj.o main.o
	gcc obj.o main.o -o gm -lSDL -lSDL_image
main.o:main.c
	gcc -c main.c
obj.o:obj.c
	gcc -c obj.c
