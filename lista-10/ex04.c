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

int* reduzirArrayAMetade(int* array, int tamanho)
{
	int novoTamanho = tamanho%2==0 
		? (tamanho/2)
		: (int) (tamanho/2) + 1;
	int* metade = (int*) malloc(novoTamanho*sizeof(int));
	for (int i = 0; i<novoTamanho; i++)
	{
		metade[i] = array[i];
	}
	return metade;
}

int main()
{
	int tamanho;
	int* array;
	printf("Informe o tamanho do array: ");
	scanf("%d", &tamanho);
	
	printf("Passe abaixo todos os elementos do array:\n");
	array = preencherArrayDinamico(tamanho);
	int* arrayMetade = reduzirArrayAMetade(array, tamanho);
	int tamanhoMetade = tamanho%2==0 
		? (tamanho/2)
		: (int) (tamanho/2) + 1;

	printf("\n\n[Array original]\n");
	imprimirArrayDinamico(array, tamanho);
	
	printf("\n\n[Array reduzido a metade]\n");
	imprimirArrayDinamico(arrayMetade, tamanhoMetade);

	free(array);
	free(arrayMetade);
	return 0;
}

