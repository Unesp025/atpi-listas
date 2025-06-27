#include<stdio.h>
#include<stdlib.h>
#include "ex03-bingo.c"

int main(int argc, char *argv[])
{
    // if (argc == 0) return (1); // usar quando for passar o caminho como argumento
	// imprimirMatriz(cartela, linhas, colunas);
    gerarCsvDaCartela("./output03.csv");
    printf("Arquivo escrito com sucesso");
    return(0);
}
