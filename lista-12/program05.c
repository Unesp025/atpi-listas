#include<stdio.h>
#include "ex05.c"

int main()
{
    char caminhoCardapio[30] = "./input/cardapio.txt";
    ItemCardapio *cardapio = obterCardapioDoArquivo(caminhoCardapio);
    imprimirCardapio(cardapio);
    return(0);
}