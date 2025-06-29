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

char **redimensionarListaDePalavras(char **lista, int tamanhoAtual, int tamanhoNovo)
{
    char **resultado = (char **) realloc(lista, tamanhoNovo * sizeof(char *));
    if (resultado!=NULL) return resultado;
    return (NULL);
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

char **coletarPedido(char **cardapio, int quantidadeItens, int *tamanhoFinalPedido)
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
            if (contador == tamanhoAtual) 
            {
                entrada = -1;
                // pedido = redimensionarListaDePalavras(pedido, tamanhoAtual, tamanhoAtual+10);
            }
        }
    }
    while(entrada != -1);
    *tamanhoFinalPedido = contador; 
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

void adicionarQuantidadeAoArquivo(char caminho[50], int quantidade, int totalLinhas)
{
    char caminhoTemp[50] = "./output/temp.txt";
    FILE *input = fopen(caminho, "r");
    FILE *temp = fopen(caminhoTemp, "w");
    if (temp!=NULL)
    {
        fprintf(temp, "%d\n", quantidade);
        char linha[50];
        for(int i = 0; i < totalLinhas; i++)
        {
            fgets(linha, sizeof(linha), input);
            fprintf(temp, linha);
        }
    }
    fclose(input);
    fclose(temp);
    remove(caminho);
    rename(caminhoTemp, caminho);
}

void produzirMenuEBoleto(
    char **pedido, int tamanhoPedido, 
    char **cardapio, int tamanhoCardapio, 
    char *caminhoMenu, char *caminhoBoleto
)
{
    FILE *outputMenu = fopen(caminhoMenu, "w");
    FILE *outputBoleto = fopen(caminhoBoleto, "w");
    
    if (outputMenu!=NULL && outputBoleto!=NULL)
    {
        char *itemAtual, *precoAtual;
        int contadorItemAtualNoPedido, contadorItensNoPedido = 0;
        float precoTotal = 0;
        for (int c = 0; c < tamanhoCardapio; c+=2)
        {
            precoAtual = cardapio[c];
            itemAtual = cardapio[c+1];
            contadorItemAtualNoPedido = 0;
            for (int p = 0; p < tamanhoPedido; p++)
            {
                if (strcmp(pedido[p], itemAtual) == 0)
                {
                    contadorItemAtualNoPedido++;
                }
            }
            if (contadorItemAtualNoPedido > 0)
            {
                precoTotal += contadorItemAtualNoPedido * atof(precoAtual);
                contadorItensNoPedido ++;
                fprintf(outputMenu, "%d %s", contadorItemAtualNoPedido, itemAtual);
                fprintf(outputBoleto, "%d x R$%s\t ..... %s", contadorItemAtualNoPedido, precoAtual,itemAtual);
            }
        }
        fprintf(outputBoleto, "Total a pagar: R$%.2f", precoTotal);
        printf("Arquivo de menu criado com sucesso em: %s\n", caminhoMenu);
        printf("Arquivo de boleto criado com sucesso em: %s\n", caminhoBoleto);
        fclose(outputMenu);
        fclose(outputBoleto);
        adicionarQuantidadeAoArquivo(caminhoMenu, contadorItensNoPedido, contadorItensNoPedido);
        adicionarQuantidadeAoArquivo(caminhoBoleto, contadorItensNoPedido, contadorItensNoPedido+1);
    }
}
