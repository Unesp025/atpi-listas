#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex05-menu.c"

int main()
{
    char caminho[50] = "./input/menu.txt";
    char **resposta = obterMenuDeArquivo(caminho);
    int tamanho = obterQuantidadeItens(caminho)*2;
    imprimirMatriz(resposta, tamanho);
    
    for (int i = 0; i < tamanho; i++)    
        free(resposta[i]);
    free(resposta);
    return(0);
}