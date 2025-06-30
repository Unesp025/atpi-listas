#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nome[50];
    float notaEx, notaP1, notaP2;
} Aluno;

typedef struct no
{
    Aluno *aluno;
    struct no *proximo;
} No;

Aluno *inicializarAluno(char nome[50], float notaEx, float notaP1, float notaP2)
{
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    if (aluno==NULL) return NULL;
    strcpy(aluno->nome, nome);
    aluno->notaEx = notaEx;
    aluno->notaP1 = notaP1;
    aluno->notaP2 = notaP2;
    return aluno;
}

float calcularMedia(Aluno *aluno)
{
    float mediaProvas = (aluno->notaP1 * 4 + aluno->notaP2 * 6)/10;
    return aluno->notaEx*0.2 + mediaProvas*0.8;
}

No *inicializarNo(Aluno *aluno)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo==NULL) return NULL; // espaço solicitado não está disponível na memoria
    novo->aluno = aluno;
    novo->proximo = NULL;

    return novo;
}

No *adicionarNo(No *lista, Aluno *aluno)
{
    if (lista->proximo==NULL)
    {
        No *novo = inicializarNo(aluno);
        lista->proximo = novo;
        return (novo);
    }
    else 
    {
        return(adicionarNo(lista->proximo, aluno));
    }
}

void imprimirAlunos(No *lista)
{
    No *atual = lista;
    while (atual!=NULL)
    {
        printf("\nNome: %s\nMedia: %.2f\n", atual->aluno->nome, calcularMedia((atual->aluno)));
        atual = atual->proximo;
    }
}

void liberarLista(No *head)
{
    while (head->proximo!=NULL)
    {
        No *temp = head->proximo;
        free(head->aluno);
        free(head);
        head = temp;
    }
}

int main()
{
    Aluno *a, *b, *c;
    a = inicializarAluno("adelaide", 6.7, 8.0, 8.3);
    b = inicializarAluno("barto", 7.8, 6.0, 7.6);
    c = inicializarAluno("coliano", 8.9, 7.0, 7.5);
    No *alunos = inicializarNo(a);
    adicionarNo(alunos, b);
    adicionarNo(alunos, c);

    imprimirAlunos(alunos);

    free(a);
    free(b);
    free(c);
    free(alunos);
    return(0);
}
