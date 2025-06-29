#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex05-menu.c"

int main()
{
    char caminhoMenu[50] = "./input/menu.txt";
    char caminhoPrecos[50] = "./input/tabela-precos.txt";

    int tamanho = obterQuantidadeItens(caminhoMenu)*2;
    char **resposta = obterListaDoArquivo(caminhoMenu);
    imprimirMatriz(resposta, tamanho);
 
    char **precos = obterListaDoArquivo(caminhoPrecos);
    imprimirMatriz(precos, 7*2);
    // exibirCardapio(precos, 7*2);

    for (int i = 0; i < tamanho; i++)    
        free(resposta[i]);
    free(resposta);
    
    for (int i = 0; i < tamanho; i++)    
        free(precos[i]);
    free(precos);

    return(0);
}