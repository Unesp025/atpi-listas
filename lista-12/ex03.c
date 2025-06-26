#include<stdio.h>

/*
    int *vetor = (int*)malloc(sizeof(int));
    matriz com ponteiros: 
    int **matriz = (int**) malloc(sizeof(int));
        - para cada espaço na matriz, alocar um vetor.
*/

/*
    Lista de nos:
    (valor)-->(prox.)-->NULL

*/

// é uma lista.
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// deve ser uma lista de listas
typedef struct noLinha
{
    No *valores;
    struct noLinha *proximo;
} NoLinha;
