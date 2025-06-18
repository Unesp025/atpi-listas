#include<stdio.h>
#include<stdlib.h>

int* preencherArrayDinamico(int tamanho)
{
	int* array = malloc(tamanho * sizeof(int));
	int value;
	for (int i = 0; i<tamanho; i++)
	{
		printf("[%d]: ", i);
		scanf("%d", &value);
		array[i] = value;
	}
	return array;
}

void imprimirArrayDinamico(int tamanho)
{

}

int* reduzirArrayAMetade(int tamanho)
{
	
}

int main()
{
	int tamanho;
	int* array;
	printf("Informe o tamanho do array: ");
	array = preencherArrayDinamico(tamanho);

	free();
	return 0;
}

