#include<stdio.h>

typedef struct 
{
    char nome[50];
    float notaExercicios;
    float notaProva01;
    float notaProva02;
} Aluno;

typedef struct no
{
    Aluno *aluno;
    struct no *proximo;
} No;

float calcularMedia(Aluno *aluno)
{
    float provas = ( aluno->notaProva01*4 + aluno->notaProva02*6)/10;
    return (aluno->notaExercicios* 0.2 + provas * 0.8);
}

void imprimirMedia(No *listaAlunos)
{
    No *atual = listaAlunos;
    while (atual->proximo!=NULL)
    {
        printf("\nAluno: %s\nMedia: %.2f\n", atual->aluno->nome, calcularMedia(atual->aluno));
        atual = atual->proximo;
    }
}

int main()
{
    // Aluno *a = (Aluno *) malloc(sizeof(Aluno));
    // Aluno *b = (Aluno *) malloc(sizeof(Aluno));
    Aluno a, b;
    No na, nb;

    a.notaExercicios = 3.0;
    a.notaProva01 = 5.0;
    a.notaProva02 = 8.0;

    b.notaExercicios = 2.0;
    b.notaProva01 = 6.0;
    b.notaProva02 = 4.0;

    na.aluno = &a;
    nb.aluno = &b;
    na.proximo = &nb;

    imprimirMedia(&na);
    return(0);
}