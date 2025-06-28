#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        
        while (fgets(linha, tamanhoLinha, input))
        {
            printf("%s", linha);
        }
        fclose(input); 
    }
    return NULL;
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