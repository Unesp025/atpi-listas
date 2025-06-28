#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **alocarMatriz(int linhas, int colunas)
{
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        int *linha = (int *) malloc(colunas * sizeof(int));
        matriz[i] = linha;
    }
    return matriz;
}

int obterLinhas(char caminho[100])
{
    FILE *input = fopen(caminho, "r");
    if (input!=NULL)
    {
        int tamanho = 20;
        char linha[tamanho];
        
        fgets(linha, tamanho, input);
        fclose(input);
        return (atoi(strtok(linha, ",")));
    }
    return (NULL);
}

int obterColunas(char caminho[100])
{
    FILE *input = fopen(caminho, "r");
    if (input!=NULL)
    {
        int tamanho = 20;
        char linha[tamanho];

        fgets(linha, tamanho, input);
        strtok(linha, ",");
        return (atoi(strtok(NULL,",")));
    }
    return (NULL);
}

int **obterMatrizDeArquivo(char caminho[100])
{
    int linhas, colunas;
    int tamanhoLinha = 20; // suporta no maximo matrizes 20x20
    char linha[tamanhoLinha];
    char *celulaAtual;
    int valorAtual;
    FILE *input = fopen(caminho, "r");

    if (input != NULL)
    {
        fgets(linha, tamanhoLinha, input);
        linhas = obterLinhas(caminho);
        colunas = obterColunas(caminho);
        
        int **matriz = alocarMatriz(linhas, colunas);
        int i = 0, j;
        
        while (fgets(linha, tamanhoLinha, input))
        {
            j = 0;
            celulaAtual = strtok(linha, ",");
            do
            {
                if (celulaAtual)
                {
                    valorAtual = atoi(celulaAtual);
                    matriz[i][j] = valorAtual;
                    celulaAtual = strtok(NULL, ",");
                }
                j++;
            }
            while(celulaAtual!= NULL);
            i++;
        }
        fclose(input); 
        return (matriz);
    }
    return NULL;
}

void imprimirMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int **somarMatrizes(int **A, int **B, int linhas, int colunas)
{
    int **resultado = alocarMatriz(linhas, colunas);
    int valorAtual;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            valorAtual = A[i][j] + B[i][j];
            resultado[i][j] = valorAtual;
        }
    }
    return (resultado);
}

/*
    quando se trata de arquivos, nao liberamos o ponteiro usando 
    free, mas sim fclose, para fechar o arquivo. 

Formas de converter char para int:
char a = "3";
int x = (int)a;     // x recebe 51... pois Alt + 5 + 1 = 3 na tabela ASCII
int y = a - '0';    // y recebe 3.
*/