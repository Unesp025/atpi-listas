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

typedef struct
{
    int quantidade;
    Produto *produto;
} Opcao;

typedef struct itemMenu
{
    Opcao *opcao;
    struct itemMenu *proximo;
} ItemMenu;

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

void imprimirProduto (Produto *produto)
{
    printf("R$%.2f\t..... %s", produto->preco, produto->nome);
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

ItemCardapio *obterItemCardapioPorIndice(ItemCardapio *cardapio, int indice)
{
    if (indice < 0) return NULL;
    int contador = 0;
    ItemCardapio *atual = cardapio;
    while (contador < indice)
    {
        if (atual->proximo == NULL) return NULL; // index out of bounds exception
        atual = atual->proximo;
        contador++;
    }
    return (atual);
}

void imprimirCardapio (ItemCardapio *cardapio)
{
    ItemCardapio *atual = cardapio;
    while(atual!=NULL)
    {
        imprimirProduto(atual->produto);
        atual = atual->proximo;
    }
}

Opcao *inicializarOpcao(int quantidade, Produto *produto)
{
    Opcao *opcao = (Opcao *) malloc(sizeof(Opcao));
    if (opcao==NULL) return NULL;

    opcao->quantidade = quantidade;
    opcao->produto = produto;
    return (opcao);
}

void imprimirOpcao(Opcao *opcao)
{
    printf("%d x %s", opcao->quantidade, opcao->produto->nome);
}

ItemMenu *inicializarItemMenu(Opcao *opcao)
{
    ItemMenu *item = (ItemMenu *) malloc(sizeof(ItemMenu));
    if (item==NULL) return NULL;
    item->opcao = opcao;
    item->proximo = NULL;
    return (item);
}

void imprimirMenu(ItemMenu *menu)
{
    ItemMenu *atual = menu;
    while(atual != NULL)
    {
        printf("%d x %s\n", atual->opcao->quantidade, atual->opcao->produto->nome);
        atual = atual->proximo;
    }
}

int obterQuantidadeItensMenu(ItemMenu *menu)
{
    ItemMenu *atual = menu;
    int contador = 0;
    while(atual!=NULL)
    {
        contador++;
        atual = atual->proximo;
    }
    return (contador);
}

ItemMenu *adicionarItemAoMenu(ItemMenu *menu, Opcao *opcao)
{
    if (menu->proximo==NULL)
    {
        ItemMenu *novo = inicializarItemMenu(opcao);
        menu->proximo = novo;
        return (novo);
    }
    return (adicionarItemAoMenu(menu->proximo, opcao));
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

void exibirCardapioIndexado(ItemCardapio *cardapio)
{
    int indice = 1;
    ItemCardapio *itemAtual = cardapio;
    printf("\n~ Menu ~\n-1 - Concluir pedido\n 0 - Exibir pedido\n");
    while (itemAtual!=NULL)
    {
        printf("%d - R$%.2f\t..... %s", indice, itemAtual->produto->preco, itemAtual->produto->nome);
        itemAtual = itemAtual->proximo;
        indice++;
    }
}

ItemMenu *coletarPedido(ItemCardapio *cardapio)
{
    int entrada, quantidadeItems = 0;
    ItemMenu *menu;
    do
    {
        printf("\e[1;1H\e[2J");
        exibirCardapioIndexado(cardapio);
        printf("\nInforme o item que deseja adicionar ao pedido: ");
        scanf("%d", &entrada);
        if (entrada<0) break;
        if (entrada == 0)
        {
            printf("\e[1;1H\e[2J");
            printf("\n~ Pedido ~\n[ENTER] - Voltar ao cardapio\n\n");
            if (quantidadeItems>0) imprimirMenu(menu);
            else printf("Nenhum item adicionado ate o momento");
            getchar();
            getchar();
        }
        else
        {
            ItemCardapio *itemAtual = obterItemCardapioPorIndice(cardapio, entrada-1);
            if (itemAtual != NULL)
            {
                Opcao *opcaoAtual = inicializarOpcao(1, itemAtual->produto);
                imprimirOpcao(opcaoAtual);
        
                if (quantidadeItems == 0)
                {
                    menu = inicializarItemMenu(opcaoAtual);
                }
                else
                {
                    adicionarItemAoMenu(menu, opcaoAtual);
                }
                quantidadeItems++;
            }
        }
    }
    while (entrada != -1);
    return (menu);
}

void escreverArquivosMenuEBoleto(ItemMenu *menu, int quantidadeItens, char caminhoMenuTxt[30], char caminhoBoletoTxt[30])
{
    FILE *inputMenu = fopen (caminhoMenuTxt, "w");
    FILE *inputBoleto = fopen(caminhoBoletoTxt, "w");
    
    ItemMenu *atual = menu;
    fprintf(inputMenu, "%d\n", quantidadeItens);
    fprintf(inputBoleto, "%d\n", quantidadeItens);
    while (atual!=NULL)
    {
        fprintf(inputMenu, "%d x %s",
          atual->opcao->quantidade, atual->opcao->produto->nome
        );
        fprintf(inputBoleto, "%d x R$%.2f\t..... %s",
            atual->opcao->quantidade, atual->opcao->produto->preco, atual->opcao->produto->nome
        );
        atual = atual->proximo;
    }

    // calcular preco total;
    fclose(inputMenu);
    fclose(inputBoleto);
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