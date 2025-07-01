#include<stdio.h>
#include<stdlib.h>
#include "ex05.c"

int main()
{
    char caminhoCardapio[30] = "./input/cardapio.txt";
    // ItemCardapio *cardapio = obterCardapioDoArquivo(caminhoCardapio);
    // exibirCardapioIndexado(cardapio);
    // ItemMenu *menu = coletarPedido(cardapio);    
    Produto *produtoA = inicializarProduto("chocolate", 3.50);
    Produto *produtoB = inicializarProduto("abobrinha", 2.0);
    Opcao *opcaoA = inicializarOpcao(2, produtoA);
    Opcao *opcaoB = inicializarOpcao(3, produtoB);

    printf("\nImprimindo opcoes: ");
    imprimirOpcao(opcaoA);
    imprimirOpcao(opcaoB);

    ItemMenu *menu = inicializarItemMenu(opcaoA);
    printf("\n\nMenu iniciliazado: :\n");
    imprimirMenu(menu);
    
    ItemMenu *novoItemMenu = inicializarItemMenu(opcaoB);
    printf("\nNovo item Menu: :\n");
    imprimirMenu(novoItemMenu);
    menu->proximo = novoItemMenu;
    printf("\nImprimindo manualmente:\n%d x %s\n%d x %s\n", 
        menu->opcao->quantidade, menu->opcao->produto->nome,
        menu->proximo->opcao->quantidade, menu->proximo->opcao->produto->nome
    );
    // adicionarItemAoMenu(menu, opcaoB);
    printf("\nImprimindo menu final:\n");
    imprimirMenu(menu);
    
    ItemCardapio *cardapio = inicializarItemCardapio(produtoA);
    printf("\nCardapio iniciliazado: :\n");
    imprimirCardapio(cardapio);
    
    adicionarItemAoCardapio(cardapio, produtoB);
    printf("\nCardapio final:\n");
    imprimirCardapio(cardapio);

    free(menu);
    free(cardapio);
    return(0);
}