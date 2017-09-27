/*
*
*  author: Lucas Lacerda
*  twitter: @lucaaslb
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void contLine(FILE* file, int* line){

    file = fopen(LOCAL_FILE_INPUT , "r");

    if(file == NULL){
        puts("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    int cont = 0;
    char c;

    while(fscanf(file,"%c",&c)==1) {
        if(c=='\n') cont++;
    }

    fclose(file);

    *line = cont;
}


void getValues(FILE* file, int line, int vtr[]){

    file = fopen(LOCAL_FILE_INPUT , "rt");

    if(file == NULL ){
        puts("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    char* result;
    int cont = 0, i = 0, info;

    while (i < line) {
      result =  fscanf(file, "%d", &vtr[i]);

      i++;
  }
    fclose(file);
}

void bolhas(int vtr[], int line) {


		int size = line, newSize = 0, aux = 0, i = 0;

		while (size != 0) {
                /* variavel que ira armazenar a ultima posição que foi
                    realizado uma troca
                    de forma que em um proximo laço não seja
                    necessario percorrer o vtr ate o fim
                */
            newSize = 0;
			for (i = 1; i <= size - 1; i++) {
				if (vtr[i - 1] > vtr[i]) {
					aux = vtr[i];
					vtr[i] = vtr[i - 1];
					vtr[i - 1] = aux;
					newSize = i;
				}
			}
			size = newSize;
		}
}

void setValues(FILE* file, int line, int vtr[]){

        file = fopen(LOCAL_FILE_OUTPUT, "wt");
        int i = 0;

        for (i; i<line; i++){
            fprintf(file, "%d\n", vtr[i]);
        }
}

void printVtr(int vtr[], int line) {
		printf("[ ");
		int posicao;
		   int size = 10;

		for (posicao = 0; posicao < size; posicao++) {
			printf("%d  ", vtr[posicao]);
		}
		printf("]\n");
}

int searchRecursion(int vtr[], int value, int ini, int endd){

    int i = (ini + endd) / 2;

		if (ini > endd) {
			return -1;
		} else if (value == vtr[i]) {
			return i;
		} else if (value < vtr[i]) {
			endd = i - 1;
			return searchRecursion(vtr, value, ini, endd);
		} else {
			ini = i + 1;
			return searchRecursion(vtr, value, ini, endd);
		}


}

