#include<stdio.h>
#include "ex05.c"

int main()
{
    char caminhoCardapio[30] = "./input/cardapio.txt";
    ItemCardapio *cardapio = obterCardapioDoArquivo(caminhoCardapio);
    // exibirCardapioIndexado(cardapio);
    ItemMenu *menu = coletarPedido(cardapio);    
    printf("\nImprimindo menu final:\n");
    imprimirMenu(menu);
    return(0);
}