#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char nome[50];
	float notaExercicios, notaP1, notaP2;
} Aluno;

Aluno inicializarAluno(char nome[50], float notaExercicios, float notaP1, float notaP2)
{
	Aluno aluno;
	strcpy(aluno.nome, nome);
	aluno.notaExercicios = notaExercicios;
	aluno.notaP1 = notaP1;
	aluno.notaP2 = notaP2;

	return (aluno);
}

float calcularMediaFinal(Aluno aluno)
{
	float mediaProvas = (aluno.notaP1*4 + aluno.notaP2*6)/10;
	return (aluno.notaExercicios*0.2 + mediaProvas*0.8);
}

void imprimirAluno(Aluno aluno)
{
	printf("Nome: %s\nMedia Final: %.2f", aluno.nome, calcularMediaFinal(aluno));
}

int main()
{
	Aluno a = inicializarAluno("bruno", 7.8, 6.5, 8.0);
	imprimirAluno(a);
	return(0);
}
