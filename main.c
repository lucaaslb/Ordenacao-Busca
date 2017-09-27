/*
*
*  author: Lucas Lacerda
*  twitter: @lucaaslb
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

    printf("Start ...... \n");
    int line;

    FILE* file = NULL;

    printf("Contando linhas ....\n");
    contLine(file, &line);

    int* vtr = (int *) calloc(line, sizeof(int));

    printf("Obtendo valores ..... \n");
    getValues(file, line, vtr); //obter valores do arquivo

  //  printVtr(vtr, line); // print valores obtidos
    printf("Ordenando com bubble sort .... \n");
    bolhas(vtr, line); //ordenar valores do vetor com metodo Bubble Sort

   // printVtr(vtr, line); // print valores obtidos
    printf("Criando arquivo de saida com valores ordenados ....\n ");
    setValues(file, line,vtr);

    /* Metodo de busca */
    int value = 0, find;
    puts("\nDigite um valor para ser localizado:");
    scanf("%d", &value);

    find = searchRecursion(vtr, value, 0,line);
    if (find != -1){
         printf("\nValor encontrado na linha: %d\n ", find+1);
    } else {
        puts("Valor nao encontrado! ");
    }

    return 0;
}

