#include<stdio.h>

// se a estrutura abaixo é uma lista.
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// então essa estrutura deve ser uma lista de listas... uma matriz
typedef struct noLinha
{
    No *valores;
    struct noLinha *proximo;
} NoLinha;
