#include<stdio.h>
#include<stdlib.h>

int* preencherArrayDinamico(int tamanho)
{
	int* array = (int*) malloc(tamanho * sizeof(int));
	int value;
	for (int i = 0; i<tamanho; i++)
	{
		printf("[%d]: ", i);
		scanf("%d", &value);
		array[i] = value;
	}
	return array;
}

void imprimirArrayDinamico(int* array, int tamanho)
{
	for (int i = 0; i < tamanho; i++)
	{
		printf("%d  ", array[i]);
	}
}

int* realocarEspacoDeMemoria(int* array, int novoTamanho)
{
	int* novoArray = (int*) malloc(novoTamanho*sizeof(int));
	for (int i = 0; i<novoTamanho; i++)
	{
		novoArray[i] = array[i];
	}
	return novoArray;
}

int main()
{
	int tamanho;
	int* array;
	printf("Informe o tamanho do array: ");
	scanf("%d", &tamanho);
	
	printf("\nPasse abaixo todos os elementos do array:\n");
	array = preencherArrayDinamico(tamanho);

	// Realocando memoria do ponteiro
	int tamanhoMetade = tamanho/2;
	array = realocarEspacoDeMemoria(array, tamanhoMetade);

	printf("\n[Array reduzido a metade]\n");
	imprimirArrayDinamico(array, tamanhoMetade);

	free(array);
	return 0;
}

