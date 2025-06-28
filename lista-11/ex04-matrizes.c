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

int **obterMatrizDeArquivo(char caminho[100])
{
    int linhas, colunas;
    int tamanhoLinha = 20; // suporta no maximo matrizes 20x20
    char linha[tamanhoLinha];
    char *celulaAtual;
    FILE *input = fopen(caminho, "r");

    if (input != NULL)
    {
        fgets(linha, tamanhoLinha, input);
        celulaAtual = strtok(linha, ",");
        linhas = *celulaAtual - '0';
        celulaAtual = strtok(NULL, ",");
        colunas = *celulaAtual - '0';
        printf("Linhas: %d | Colunas: %d\n", linhas, colunas);
        
        int **matriz = alocarMatriz(linhas, colunas);
        int i = 0, j = 0;
        
        while (fgets(linha, tamanhoLinha, input))
        {
            celulaAtual = strtok(linha, ",");
            do
            {
                if (celulaAtual)
                {
                    printf("%d\t", atoi(celulaAtual));
                    // matriz[i][j] = atoi(celulaAtual);
                    celulaAtual = strtok(NULL, ",");
                }
                j++;
            }
            while(celulaAtual!= NULL);
            printf("\n");
            i++;
        }
        fclose(input); 
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

int **somarMatrizes(int **A, int **B)
{

}

/*
    quando se trata de arquivos, nao liberamos o ponteiro usando 
    free, mas sim fclose, para fechar o arquivo. 

Formas de converter char para int:
char a = "3";
int x = (int)a;     // x recebe 51... pois Alt + 5 + 1 = 3 na tabela ASCII
int y = a - '0';    // y recebe 3.
*/