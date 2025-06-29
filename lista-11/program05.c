#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex05-menu.c"

int main()
{
    char caminhoMenu[50] = "./output/menu.txt";
    char caminhoBoleto[50] = "./output/boleto.txt";
    char caminhoCardapio[50] = "./input/tabela-precos.txt";

    // int tamanho = obterQuantidadeItens(caminhoMenu)*2;
    // char **resposta = obterListaDoArquivo(caminhoMenu);
    // imprimirMatriz(resposta, tamanho);
    
    int tamanhoCardapio = obterQuantidadeItens(caminhoCardapio)*2;
    char **cardapio = obterListaDoArquivo(caminhoCardapio);
    imprimirMatriz(cardapio, tamanhoCardapio);

    int tamanhoPedido;
    char **pedido = coletarPedido(cardapio, tamanhoCardapio, &tamanhoPedido);
    imprimirPedido(pedido, tamanhoPedido);
    
    produzirMenuEBoleto(pedido, tamanhoPedido, cardapio, tamanhoCardapio, caminhoMenu, caminhoBoleto);

    liberarListaDePalavras(cardapio, tamanhoCardapio);
    liberarListaDePalavras(pedido, tamanhoPedido);
    return(0);
}