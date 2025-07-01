#include<stdio.h>
#include<stdlib.h>
#include "ex05.c"

int main()
{
    char caminhoCardapio[30] = "./input/cardapio.txt";
    char caminhoMenu[30] = "./output/menu.txt";
    char caminhoBoleto[30] = "./output/boleto.txt";
    ItemCardapio *cardapio = obterCardapioDoArquivo(caminhoCardapio);
    exibirCardapioIndexado(cardapio);
    ItemMenu *menu = coletarPedido(cardapio);    
    escreverArquivosMenuEBoleto(menu, obterQuantidadeItensMenu(menu), caminhoMenu, caminhoBoleto);

    return(0);
}