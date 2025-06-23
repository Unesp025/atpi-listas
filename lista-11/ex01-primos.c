#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int inicio, fim;
	bool ehPrimo;
	inicio = atoi(argv[1]);
	fim = atoi(argv[2]);

	printf("Primos entre %d e %d: \n", inicio, fim);
	for (int i = inicio; i<= fim; i++)
	{
		ehPrimo = true;
		if (i<2 || (i % 2==0 && i!=2)) ehPrimo=false;
		for (int j = 3; j < i;j++)
		{
			if (i%j==0) 
			{
				ehPrimo = false;
				break;
			}
		}
		if (ehPrimo) printf("%d ", i);
	}
	return(0);
}
