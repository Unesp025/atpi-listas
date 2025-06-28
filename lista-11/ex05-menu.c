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

void imprimirMatriz(char **matriz, int linhas)
{
    printf("\n\nimprimir:\n");
    for (int i = 0; i < linhas; i+=2)
    {
        // printf("%s x\t %s\n", matriz[i], matriz[i+1]);
        printf("ptr: %s x %senderecos: %d \tx %d\n\n", 
                matriz[i], matriz[i+1],
                &matriz[i], &matriz[i+1]);
    }
}

char **obterMenuDeArquivo(char caminho[50])
{
    FILE *input = fopen(caminho, "r");
    if (input!=NULL)
    {
        int tamanho = 50;
        char linha[tamanho];
        int quantidadeItens = obterQuantidadeItens(caminho);
        char **ponteiroListaPedidos = alocarListaDePalavras(quantidadeItens * 2, tamanho); // por anotar tambem a qtd de cada item
        char arrayListaPedidos[quantidadeItens*2][tamanho];
        fgets(linha, tamanho, input); // pular a linha de quantidade de itens.

        // char *itemAtualQuantidade;
        // char *itemAtualNome;
        for (int l = 0; l < quantidadeItens*2; l+=2)
        {
            fgets(linha, tamanho, input);
            
            strcpy(arrayListaPedidos[l], (strtok(linha, " ")));
            strcpy(arrayListaPedidos[l+1], (strtok(NULL, " ")));

            ponteiroListaPedidos[l] = arrayListaPedidos[l];
            ponteiroListaPedidos[l+1] = arrayListaPedidos[l+1];
            
            printf("ptr: %s x %senderecos: %d \tx %d\n\n", 
                ponteiroListaPedidos[l], ponteiroListaPedidos[l+1],
                &ponteiroListaPedidos[l], &ponteiroListaPedidos[l+1]);
        }
        printf("\nImprimindo array:\n");
        for (int i = 0; i<quantidadeItens*2; i++)
        {
            printf("%s", ponteiroListaPedidos[i]);
        }
        // for (int i = 0; i < quantidadeItens*2; i+=2)
        // {
        // printf("%s x\t %s\n", matriz[i], matriz[i+1]);
        // printf("ptr: %s x %senderecos: %d \tx %d\n\n", 
        //         ponteiroListaPedidos[i], ponteiroListaPedidos[i+1],
        //         &ponteiroListaPedidos[i], &ponteiroListaPedidos[i+1]);
        // }
        imprimirMatriz(ponteiroListaPedidos, quantidadeItens*2);

        fclose(input);
        return (ponteiroListaPedidos);
    }
    return (NULL);
}

// fazer tabela de precos lida de um arquivo (char caminho[50], char **tabelaPrecos)
void escreverBoleto(char caminho[50])
{

}

int main()
{
    char caminhoMenu[50] = "./input/menu.txt";
    imprimirMatriz(obterMenuDeArquivo(caminhoMenu), obterQuantidadeItens(caminhoMenu)*2);
    // char **pedidos = obterMenuDeArquivo(caminhoMenu);

    // imprimirMatriz(pedidos, quantidade);

    // for (int i = 0; i < (quantidade); i++)
    // {
    //     free(pedidos[i]);
    // }
    // free(pedidos);
    return(0);
}

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
