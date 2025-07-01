#include<stdio.h>
#include<stdlib.h>
#include "ex05.c"

int main()
{
    char caminhoCardapio[30] = "./input/cardapio.txt";
    ItemCardapio *cardapio = obterCardapioDoArquivo(caminhoCardapio);
    exibirCardapioIndexado(cardapio);
    ItemMenu *menu = coletarPedido(cardapio);    

    return(0);
}