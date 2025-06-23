#include<stdio.h>
#include<stdlib.h>

float arredondar(float valor, int casas)
{
	int fator = 1;
	for (int i = 0; i < casas; i++)
	{
		fator *= 10;
	}
	return (float)(int)((valor * fator) + 0.5) / (float)fator;
}

int main(int argc, char* argv[])
{
	float valor, resultado;
	int casas;
	valor = atof(argv[1]);
	casas = atoi(argv[2]);
	resultado = arredondar(valor, casas);
	printf("Valor '%f' arredondado: %f", valor, resultado);
	return(0);
}

