#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **alocarListaDePalavras(int linhas, int colunas)
{
    char **ptrPalavras = (char **) malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++)
    {
        ptrPalavras[i] = (char *) malloc(colunas * sizeof(char));
    } 

    return ptrPalavras;
}

char **redimensionarListaDePalavras(char **lista, int tamanhoAtual, int novoTamanho)
{
    char **resultado = (char **) malloc(novoTamanho * sizeof(char *));
    for (int i = 0; i < novoTamanho; i++)
    {
        strcpy(resultado[i], lista[i]);
    }
    return resultado;
}

void liberarListaDePalavras(char **lista, int tamanho)
{
    for (int i = 0; i < tamanho; i++)    
        free(lista[i]);
    free(lista);
}

int obterQuantidadeItens(char caminho[50])
{
    FILE *input = fopen(caminho, "r");
    int tamanho = 9;
    char linha[tamanho]; // aceitar no maximo uma qunaitdade de itens com 9 casas ***.***.***. (centena de milhão)
    if (input!=NULL)
    {
        fgets(linha, tamanho, input);
        fclose(input);
        return (atoi(linha));
    }
    return (NULL);
}

void imprimirPedido(char **pedido, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("* %s", pedido[i]);
    }
}

void imprimirMatriz(char **matriz, int linhas)
{
    for (int i = 0; i < linhas; i+=2)
    {
        printf("%s x %s", matriz[i], matriz[i+1]); 
    }
}

void exibirCardapio(char **cardapio, int quantidadeItens)
{
    int itemAtual;
    printf("\e[1;1H\e[2J");
    printf("\n~ Menu ~\n-1 - concluir pedido\n 0 - exibir pedido\n\n");
    for (int m = 0; m < quantidadeItens; m+=2)
    {
        itemAtual = (m/2)+1;
        printf("%d - R$%s\t..... %s", itemAtual, cardapio[m], cardapio[m+1]); 
    }
}

char **coletarPedido(char **cardapio, int quantidadeItens)
{
    int entrada, itemAtual, tamanhoAtual = 10, contador = 0;
    char **pedido = alocarListaDePalavras(tamanhoAtual, 30);
    do 
    {
        exibirCardapio(cardapio, quantidadeItens);
        printf("\n-\nInforme a opcao que deseja: ");
        scanf("%d", &entrada);
        
        if (entrada == 0) 
        {
            printf("\e[1;1H\e[2J");
            printf("\n~ Pedido ~\n[ENTER] - voltar ao menu\n\n");
            imprimirPedido(pedido, contador);
            getchar();
            getchar();
        }
        else
        {
            itemAtual = ((entrada-1)*2)+1;
            if (itemAtual<=quantidadeItens-1 && entrada > 0)
            {
                strcpy(pedido[contador],cardapio[itemAtual]);
                contador++;
            }
        }
    }
    while(entrada != -1);
    return (pedido);
}

char **obterListaDoArquivo(char caminho[50])
{
    FILE *input = fopen(caminho, "r");
    if (input!=NULL)
    {
        int tamanho = 50;
        char linha[tamanho];
        int quantidadeItens = obterQuantidadeItens(caminho);
        char **ponteiroListaPedidos = alocarListaDePalavras(quantidadeItens * 2, tamanho);
        char *itemAtualQuantidade;
        char *itemAtualNome;
        fgets(linha, tamanho, input); 

        for (int l = 0; l < quantidadeItens*2; l+=2)
        {
            fgets(linha, tamanho, input);
            
            itemAtualQuantidade = strtok(linha, " ");
            itemAtualNome = strtok(NULL, " ");

            strcpy(ponteiroListaPedidos[l], itemAtualQuantidade);
            strcpy(ponteiroListaPedidos[l+1], itemAtualNome);
        }
        fclose(input);
        return (ponteiroListaPedidos);
    }
    return (NULL);
}

// fazer tabela de precos lida de um arquivo (char caminho[50], char **tabelaPrecos)
void escreverBoleto(char caminho[50], char **menu, char **tabelaPrecos)
{

}
