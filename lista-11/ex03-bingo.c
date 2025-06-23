#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char** alocarMatrizChar(int linhas, int colunas)
{
	char** matriz = (char**)malloc(linhas*sizeof(char*));
	for (int i = 0; i< linhas; i++)
	{
		matriz[i] = (char*)malloc(colunas*sizeof(char));
	}
	return matriz;
}

char* gerarColunaAleatoria(int minimo, int maximo, int tamanho)
{
	srand(time(NULL));
	char* coluna = (char*) malloc(tamanho*sizeof(char));
	char valor;
	for (int i = 0; i < tamanho; i++)
	{
		valor = rand()%((maximo-minimo+1)+minimo) + '0';
		coluna[i] = valor;
	}
	return coluna;
}

char** gerarCartela()
{
	int minimo=1, maximo=15;
	char** cartela = alocarMatrizChar(6, 5);
	char* titulo[5] = {"B","I","N","G","O"};
	char* coluna;

	for (int j = 0; j<5; j++)
		cartela[0][j] = titulo[j][0];
	
	for (int i = 0; i<5; i++)
	{
		coluna = gerarColunaAleatoria(minimo, maximo, 5);
		minimo+=15;
		maximo+=15;
		for (int j = 1; j < 6; j++)
		{
			cartela[j][i] = coluna[i];
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

void imprimirMatriz(char** matriz, int linhas, int colunas)
{
	for (int i = 0; i<linhas; i++)
	{
		for (int j = 0; j<colunas; j++)
		{
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	// char** cartela = gerarCartela();
	// imprimirMatriz(cartela, 6, 5);
	// imprimirCartela();
	char* coluna = gerarColunaAleatoria(16, 30, 5);
	for (int i =0; i<5;i++)
		printf("%c", coluna[i]);
	return(0);
}

