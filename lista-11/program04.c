#include<stdio.h>
#include "ex04-matrizes.c"

int main()
{
    char caminhoMatrizA[30] = "./input/matrizA.txt";
    char caminhoMatrizB[30] = "./input/matrizB.txt";
    
    int linhas, colunas;
    linhas =obterLinhas(caminhoMatrizA); 
    colunas = obterColunas(caminhoMatrizA);

    int **matrizA = obterMatrizDeArquivo(caminhoMatrizA);
    int **matrizB = obterMatrizDeArquivo(caminhoMatrizB);
    int **soma = somarMatrizes(matrizA, matrizB, linhas, colunas);

    printf("\nMatriz A:\n");
    imprimirMatriz(matrizA, linhas, colunas);
    printf("\nMatriz B:\n");
    imprimirMatriz(matrizB, linhas, colunas);
    
    printf("\nSoma das matrizes:\n");
    imprimirMatriz(soma, linhas, colunas);
    
    for (int a = 0 ;a < linhas; a++)
        free(matrizA[a]);
    for (int b = 0 ;b < linhas; b++)
        free(matrizA[b]);

    free(matrizA);
    free(matrizA);
    return (0);
}