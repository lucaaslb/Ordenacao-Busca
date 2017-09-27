#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define LOCAL_FILE_INPUT "/home/lucaaslb/Documentos/code/C/Ordenacao_Busca/input.txt"
#define LOCAL_FILE_OUTPUT "/home/lucaaslb/Documentos/code/C/Ordenacao_Busca/output.txt"

/* Metodo que conta as linahs do arquivo para poder criar um vetor do tamanho correto*/
void contLine(FILE* file, int* line);

/* obtem valores do arquivo para preencher vetor */
void getValues(FILE* file, int line, int vtr[]);

/* cria um arquivo de saida com os valores ordenados do vetor*/
void setValues(FILE* file, int line, int vtr[]);

/* ordena o vetor utilizando o metodo Bubble Sort*/
void bolhas(int vtr[], int line) ;

/* imprime no console os valores do vetor */
void printVtr(int vtr[], int line);

/* metodo de busca binaria para vetor ordenado*/
int searchRecursion(int vtr[], int value, int ini, int endd);
#endif // HEADER_H_INCLUDED
