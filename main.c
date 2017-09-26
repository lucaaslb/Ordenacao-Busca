#include <stdio.h>
#include <stdlib.h>

#define LOCAL_FILE_INPUT "/home/lucaaslb/Documentos/code/C/Ordenacao_Busca/input.txt"
#define LOCAL_FILE_OUTPUT "/home/lucaaslb/Documentos/code/C/Ordenacao_Busca/output.txt"

void contLine(FILE* file, int* line){

    file = fopen(LOCAL_FILE_INPUT , "r");

    if(file == NULL ){
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
        if (result){  // Se foi possível ler
	      //   printf("%d\n", vtr[i]);
        }
        i++;
  }

    fclose(file);
}

void setValues(FILE* file, int line, int vtr[]){

        file = fopen(LOCAL_FILE_OUTPUT, "wt");
        int i = 0;

        for (i; i<line; i++){
            fprintf(file, "%d\n", vtr[i]);
        }
}

void bolhas(int vtr[], int line) {

		int size = line;
		int newSize, aux = 0, i = 0;

		while (size != 0) {
			newSize = 0; // variavel que ira armazenar a ultima posição que foi
							// realizado uma troca
							// de forma que em um proximo laço não seja
							// necessario percorrer o vtr ate o fim

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

void printVtr(int vtr[], int line) {
		printf("[ ");
		int posicao;
		   int size = 10;

		for (posicao = 0; posicao < size; posicao++) {
			printf("%d  ", vtr[posicao]);
		}
		printf("]\n");

	}

/*
// metodo Insertion Sort de ordenacao

void InsertionSort(int vtr[]){

     int size = 10;
		int i, j, aux;
		for (i = 1; i <= size - 1; i++) {
			j = i;
			while (j > 0 && vtr[j - 1] > vtr[j]) {
				aux = vtr[j];
				vtr[j] = vtr[j - 1];
				vtr[j - 1] = aux;
				j = j - 1;
			}
		}
}

*/

int main() {

    int line;

    FILE* file = NULL;

    contLine(file, &line);

    int* vtr = (int *) calloc(line, sizeof(int));

    getValues(file, line, vtr); //obter valores do arquivo

    printVtr(vtr, line); // print valores obtidos

    bolhas(vtr, line); //ordenar valores do vetor com metodo Bubble Sort

    printVtr(vtr, line); // print valores obtidos

    setValues(file, line,vtr);

    return 0;
}


