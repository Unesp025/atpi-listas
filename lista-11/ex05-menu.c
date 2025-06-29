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

char **redimensionarListaDePalavras(char **lista, int novoTamanho)
{
    char **resultado = (char **) malloc(novoTamanho * sizeof(char *));
    for (int i = 0; i < novoTamanho; i++)
    {
        strcpy(resultado[i], lista[i]);
    }

    return resultado;
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
        printf("%s\n", pedido[i]);
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
    int entrada, itemAtual, tamanhoAtual = 10, contador = 0;
    char **pedido = alocarListaDePalavras(tamanhoAtual, 30);
    do 
    {
        printf("\e[1;1H\e[2J");
        printf("\n~ Menu ~\n-1 - concluir pedido\n 0 - exibir pedido\n\n");
        for (int m = 0; m < quantidadeItens; m+=2)
        {
            itemAtual = (m/2)+1;
            printf("%d - R$%s\t..... %s", itemAtual, cardapio[m], cardapio[m+1]); 
        }
        printf("\n-\nInforme a opcao que deseja: ");
        scanf("%d", &entrada);

        if (entrada == 0) 
        {
            imprimirPedido(pedido, contador+1);
        }
        else
        {
            itemAtual = ((entrada-1)*2)+1;
            if (itemAtual<=quantidadeItens-1 && entrada > 0)
            {
                printf("%s", cardapio[itemAtual]);
                // strcpy(pedido[contador],cardapio[((entrada-1)*2)+1]);
                // pedido[contador]
                contador++;
            }
        }
    }
    while(entrada != -1);
}

char **obterListaDoArquivo(char caminho[50])
{
    FILE *input = fopen(caminho, "r");
    if (input!=NULL)
    {
        int tamanho = 50;
        char linha[tamanho];
        int quantidadeItens = obterQuantidadeItens(caminho);
        char **ponteiroListaPedidos = alocarListaDePalavras(quantidadeItens * 2, tamanho); // por anotar tambem a qtd de cada item
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
        // free(itemAtualQuantidade);
        // free(itemAtualNome);         // quando liberados esses espacos, o programa nao funciona.
        fclose(input);
        return (ponteiroListaPedidos);
    }
    return (NULL);
}

// fazer tabela de precos lida de um arquivo (char caminho[50], char **tabelaPrecos)
void escreverBoleto(char caminho[50], char **menu, char **tabelaPrecos)
{

}

/*
1 x sanduba         ..... R$5,00 (R$5,00/unidade)
4 x sache-ketchup   ..... R$8,00 (R$2,00/unidade)
*/

/*
teoria:
    Sabemos que uma palavra é um array de chars. Um array de
    chars pode ser representado por um ponteiro de char.
        Enderecos sequenciais na memoria armazenam, cada um,
        uma letra da palavra.
    Assim, um array de palavras é um array de array de chars. 
    Para fazer isso com ponteiros, alocamos um char **ptr.
        Para cada endereco sequencial alocado, aponta-se para o 
        array que contem uma palvra.
    Um ponteiro de ponteiro de char é uma LISTA de palavras.
    Uma matriz é uma LISTA de LISTAS.
    Uma matriz de ints é um PONTEIRO de PONTEIRO de int. 
    Logo uma matriz de chars é um PONTEIRO de PONTEIRO de PONTEIRO de chars.  
    
ideia:
    Para evitar uma matriz de palavras, que envolveria char ***ptr..., 
    vamos fazer:
        Uma lista de palavras : Ponteiro de ponteiro de char. 
        Cada elemento em posição par (0, 2, 4...) é o numero de itens.
        Cada elemento em posição impar (1, 3, 5...) é o item em si. 

problema:
    Ao usar ponteiros para obter os valores de item e quantidade do arquivo,
    a cada iteração, o valor naquele endereco muda.
    Por isso, ao fim da execução, todos os enderecos apontam para goiabada...
    (que é o ultimo item do menu)

    O certo seria passar direto o valor para o ponteiro, não o endereço
*/
