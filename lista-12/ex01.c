#include<stdio.h>
#include<string.h>

// deixa pra complicar depois 
typedef struct nota
{
    float valor;
    struct nota *proxima;
} Nota;

typedef struct 
{
    char nome[50];
    float notaExercicios;
    float notaProva01;
    float notaProva02;
} Aluno;

/*
outra possibilidade
void registrarAluno(char nome[50], Aluno *a)
{
    Aluno *aluno;
    strcpy(aluno->nome, nome);

    return aluno;
}
*/

Aluno *registrarAluno(char nome[50])
{
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    strcpy(aluno->nome, nome);

    return aluno;
}

float calcularMedia(Aluno *aluno)
{
    float provas = ( aluno->notaProva01*4 + aluno->notaProva02*6)/10;
    return (aluno->notaExercicios* 0.2 + provas * 0.8);
}

int main()
{
    /*
        a outra possibilidade
        Aluno aluno; 
        registrarAluno("matheus", &aluno);
    */
    Aluno *aluno = registrarAluno("bruno");
    aluno->notaExercicios = 5.6;
    aluno->notaProva01 = 8.7;
    aluno->notaProva02 = 6.3;

    printf("media de %c: %f", aluno->nome, calcularMedia(aluno));
}