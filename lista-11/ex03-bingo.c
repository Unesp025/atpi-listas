#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** alocarMatrizInt(int linhas, int colunas)
{
	int** matriz = (int**)malloc(linhas*sizeof(int*));
	for (int i = 0; i< linhas; i++)
	{
		matriz[i] = (int*)malloc(colunas*sizeof(int));
	}
	return matriz;
}

int* gerarColunaAleatoria(int minimo, int maximo, int tamanho)
{
	srand(time(NULL));
	int* coluna = (int*) malloc(tamanho*sizeof(int));
	int valor;
	for (int i = 0; i < tamanho; i++)
	{
		valor = rand()%((maximo-minimo+1)+minimo);
		coluna[i] = valor;
	}
	return coluna;
}

int** gerarCartela()
{
	int minimo=1, maximo=15;
	int* coluna;
	int** cartela = alocarMatrizInt(5, 5);
	char titulo[5] = {'B','I','N','G','O'};

	for (int i = 0; i<5; i++)
	{
		coluna = gerarColunaAleatoria(minimo, maximo, 5);
		minimo+=15;
		maximo+=15;
		for (int j = 0; j < 5; j++)
		{
			cartela[j][i] = coluna[j];
		}
	}
	return cartela;
}

void gerarCsvDaCartela()
{

}

void imprimirCartela()
{
	int valor, inicio, fim;
	srand(time(NULL));
	printf("B,I,N,G,O\n");
	for (int i = 0; i<5;i++)
	{
		inicio = 1;
		fim = 15;
		for (int j=0;j<5;j++)
		{
			valor = rand()%(fim - inicio + 1)+inicio;
			inicio += 15;
			fim += 15;
			if (i==2 && j==i) printf("FREE,");
			else printf("%d,", valor);
		}
		printf("\n");
	}
}

void imprimirMatriz(int** matriz, int linhas, int colunas)
{
	for (int i = 0; i<linhas; i++)
	{
		for (int j = 0; j<colunas; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int** cartela = gerarCartela();
	imprimirMatriz(cartela, 5, 5);
	return(0);
}

