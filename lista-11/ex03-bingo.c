#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int *ordenarLinha(int *linha, int tamanho, bool ordenarAsc)
{
	int *ordenado = linha;
	int trocasIdentificadas;
	do
	{
		trocasIdentificadas = 0;
		for (int i = 0; i < tamanho-1; i++)
		{
			bool comparacao = ordenarAsc
				? ordenado[i]>ordenado[i+1]
				: ordenado[i]<ordenado[i+1];
			if (comparacao)
			{
				int temp = ordenado[i];
				ordenado[i] = ordenado[i+1];
				ordenado[i+1] = temp;
				
				trocasIdentificadas++;
			}
		}
	}
	while(trocasIdentificadas > 0);
	return (ordenado);
}

int *gerarArrayAleatorioUnico(int minimo, int maximo, int tamanho)
{
	if (tamanho == 1)
	{
		int valor = (rand()%(maximo-minimo+1)+minimo);
		int *ret = &valor;
		return ret;
	}
	if (maximo-minimo+1 < tamanho) return NULL;
	srand(time(NULL));
	int *array = (int *) malloc(tamanho*sizeof(int));
	int valor;
	bool valorEhUnico = false;
	while (!valorEhUnico)
	{
		for (int i = 0; i < tamanho; i++)
		{
			valor = rand()%(maximo-minimo+1)+minimo;
			for (int j = 0; j < i; j++)
			{
				if (valor == array[j])
				{
					valorEhUnico = false;
					break;
				}
				valorEhUnico = true;
			}
			array[i] = valor;
		}
	}
	return array;
}

int **alocarMatrizInt(int linhas, int colunas)
{
	int **matriz = (int **) malloc(linhas*sizeof(int *));
	for (int i = 0; i< linhas; i++)
	{
		matriz[i] = (int *) malloc(colunas*sizeof(int));
	}
	return matriz;
}

int **gerarCartela()
{
	int minimo=1, maximo=15;
	int *coluna;
	int **cartela = alocarMatrizInt(5, 5);

	for (int i = 0; i<5; i++)
	{
		int *colunaDesordenada = gerarArrayAleatorioUnico(minimo, maximo, 5);
		coluna = ordenarLinha(colunaDesordenada, 5, true);
		minimo+=15;
		maximo+=15;
		for (int j = 0; j < 5; j++)
		{
			cartela[j][i] = coluna[j];
		}
	}
	cartela[2][2] = -1;
	return cartela;
}

void gerarCsvDaCartela(char caminho[100])
{
	FILE *output = fopen(caminho, "w");
	if (output != NULL)
	{
		int **cartela = gerarCartela();
		int atual;
		fprintf(output, "B,I,N,G,O\n");
		for (int i = 0; i< 5; i++)
		{
			for (int j =0; j < 5; j++)
			{
				atual = cartela[i][j];
				if (atual<0) fprintf(output, "FREE,");
				else
				{
					fprintf(output, "%d", atual);
					if (j!=4) fprintf(output, ",");
				} 
			}
			fprintf(output, "\n");
		}
		fclose(output);
		free(cartela);
	}
}

void gerarImprimirCartela()
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

void imprimirLinha(int *linha, int tamanho)
{
	for (int i = 0; i < tamanho; i++)
	{
		printf("%d\t", linha[i]);
	}
}

void imprimirMatriz(int **matriz, int linhas, int colunas)
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
