#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nome[30];
    float preco;
} Produto;

typedef struct itemCardapio
{
    Produto *produto;
    struct itemCardapio *proximo;
} ItemCardapio;


Produto *inicializarProduto(char nome[30], float preco)
{
    Produto *prod = (Produto *) malloc(sizeof(Produto));
    if (prod!=NULL)
    {
        strcpy(prod->nome, nome);
        prod->preco = preco;
        return prod;
    }
    return (NULL);
}

void atualizarProduto(Produto *produto, char novoNome[30], float novoPreco)
{
    strcpy(produto->nome, novoNome);
    produto->preco = novoPreco;
}

ItemCardapio *inicializarItemCardapio(Produto *produto)
{
    ItemCardapio *item = (ItemCardapio *) malloc(sizeof(ItemCardapio));
    if (item != NULL)
    {
        item->produto = produto;
        item->proximo = NULL;
        return (item);
    }
    return (NULL);
}

ItemCardapio *adicionarItemAoCardapio(ItemCardapio *cardapio, Produto *produto)
{
    if (cardapio->proximo==NULL)
    {
        ItemCardapio *novoItem = inicializarItemCardapio(produto);
        cardapio->proximo = novoItem;
        return (novoItem);
    }
    else{
        return(adicionarItemAoCardapio(cardapio->proximo, produto));
    }
}

void imprimirProduto (Produto *produto)
{
    printf("R$%.2f\t..... %s", produto->preco, produto->nome);
}

void imprimirCardapio (ItemCardapio *cardapio)
{
    ItemCardapio *atual = cardapio;
    while(atual->proximo!=NULL)
    {
        imprimirProduto(atual->produto);
        atual = atual->proximo;
    }
    free(atual);
}

ItemCardapio *obterCardapioDoArquivo(char caminho[30])
{
    ItemCardapio *cardapio;
    FILE *input = fopen(caminho, "r");
    int quantidadeItens, tamanhoLinha = 30;
    char linha[tamanhoLinha];

    fgets(linha, tamanhoLinha, input);
    quantidadeItens = atoi(linha);

    char *nome; 
    float preco;
    for (int i = 0; i < quantidadeItens; i++)
    {
        fgets(linha, tamanhoLinha, input);
        preco = atof(strtok(linha, " "));
        nome = strtok(NULL, " ");
        
        Produto *produtoAtual = inicializarProduto(nome, preco);
        if (i == 0)
        {
            cardapio = inicializarItemCardapio(produtoAtual);
        }
        else
        {
            adicionarItemAoCardapio(cardapio, produtoAtual);
        }
    }
    fclose(input);
    return (cardapio);
}

/*
duvida:
    Por que usar strcpy quando dar valores para os parametros que 
    sao char [x]?
        - Strings em c são essencialemnte sequencias de chars, 
        alocados em endereços de memoria sequenciais.
    Ao atribuir um valor para um outro ponteiro, deve-se 
    atribuir a copia desse valor, não seu encereco.
        strcpy faz a copia de cada byte da string para o endereco
        destino. Usar atribuição (=) nao funciona.     

teoria:
    Arrays sao um bloco continuo de memoria, que armazena em cada 
    endereco um valor de mesmo tipo. 
    Ao definir um array como `int arr[5];`, sabe-se que o espaco
    alocado em memoria será 5 * sizeof(int);
    
    Ao iterar por um array, seu nome (neste caso `arr`) torna-se
    implicitamente um ponteiro para o endereco do primeiro elemento:
        `arr` torna-se equivalente a `&arr[0]`
    Da mesma forma, um elemento qualquer pode ser acessado usando 
    aritimética de ponteiros:
        `arr[2] == *(arr+2);`

boa pratica:
    Depois de liberar um ponteiro com `free(ptr);`, é uma boa pratica
    o seguinte:
        ptr = NULL;
    para evitar que o ptr seja acessado mesmo após liberado e acarrete 
    em 'undefined behaviour'.
*/