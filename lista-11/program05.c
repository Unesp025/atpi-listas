#include<stdio.h>
#include "ex05-menu.c"

int main()
{
    char caminhoMenu[50] = "./input/menu.txt";
    int quantidade = obterQuantidadeItens(caminhoMenu)*2;
    char **pedidos = obterMenuDeArquivo(caminhoMenu);

    // printf("%s x %s", pedidos[0], pedidos[1]);
    imprimirMatriz(pedidos, quantidade);

    for (int i = 0; i < (quantidade); i++)
    {
        free(pedidos[i]);
    }
    free(pedidos);
    return(0);
}