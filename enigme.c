#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enigme.h"

int gen_nb(){
int n_a = 1,i;
	srand(time(NULL));
	n_a = rand()%(14); // initialisation de rand
	if (n_a%3==1){

        i = n_a;
	}
	else if (n_a%3==2){

        i= n_a+2;
	}
	else {

        i=n_a+1;
	}
	return i;
}

int  gen_en(int k){
  k=gen_nb();
  int caractereLu, ligne=1;
  FILE *f = fopen("enigme.txt","r+");
  char mot[100];
  if (f==NULL)
     exit(0);
  else
      rewind(f);
       while (caractereLu!=EOF && ligne<k)
       {
           caractereLu=fgetc(f);
           if (caractereLu=='\n')
                ligne++;

       }

    fgets(mot,100,f);
    printf("%s",mot);

  system("PAUSE");
  return k;
}

void trois_en(int k){
     k=gen_nb();
  int caractereLu, ligne=1,i;
  FILE *f = fopen("enigme.txt","r+");
  char mot[100];
  if (f==NULL)
     exit(0);
  else
      rewind(f);
      for (i=0;i<3;i++){
       while (caractereLu!=EOF && ligne<k+(1/2)*i)
       {
           caractereLu=fgetc(f);
           if (caractereLu=='\n')
                ligne++;

       }

    fgets(mot,100,f);
    printf("%s",mot);

  system("PAUSE");
      }
}
