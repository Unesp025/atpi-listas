#include<stdio.h>

typedef struct 
{
    int valorInteiro;
    int valorDecimal;
} Flutuante;

/*
como nas funções abaixo é feito apenas um acesso, não
uma modificação, então não é necessário passar 'a' e 'b'
como ponteiros. Os valores podem ser passados como copias
sem prejuízo.
*/
Flutuante *somar(Flutuante a, Flutuante b)
{
    Flutuante *soma = (Flutuante*) malloc(sizeof(Flutuante));
    int parteInteira = a.valorInteiro + b.valorInteiro;
    int parteDecimal = a.valorDecimal + b.valorDecimal;
    if (soma->valorDecimal>=10000)
    {
        parteInteira++;
        parteDecimal -= 10000;
    }
    soma->valorInteiro = parteInteira;
    soma->valorDecimal = parteDecimal;
    return (soma);
}

Flutuante *subtrair(Flutuante a, Flutuante b)
{
    Flutuante *subtracao = (Flutuante *) malloc(sizeof(Flutuante));
    int parteInteira = a.valorInteiro - b.valorInteiro;
    int parteDecimal = a.valorDecimal - b.valorDecimal;
    if (parteDecimal<0)
    {
        parteInteira--;
        parteDecimal = 10000 + parteDecimal;
    }
    subtracao->valorInteiro = parteInteira;
    subtracao->valorDecimal = parteDecimal;

    return (subtracao);
}

void imprimir(Flutuante f)
{
    printf("%d.%d", f.valorInteiro, f.valorDecimal);
}

int main()
{
    Flutuante a, b;
    a.valorInteiro = 9;
    a.valorDecimal = 2345;
    b.valorInteiro = 6;
    a.valorDecimal = 7853;

    Flutuante *soma = somar(a, b);
    Flutuante *subtracao = subtrair(a, b);

    printf("Soma: ");
    imprimir(*soma);
    printf("\nSubtracao: ");
    imprimir(*subtracao);

    free(soma);
    free(subtracao);
    return (0);
}