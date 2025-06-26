
typedef struct 
{
    int valorInteiro;
    int valorDecimal;
} Flutuante;

Flutuante *somarFlutuante(Flutuante *flutuanteA, Flutuante *flutuanteB)
{
    Flutuante *soma = (Flutuante*) malloc(sizeof(Flutuante));
    int parteInteira = flutuanteA->valorInteiro + flutuanteB->valorInteiro;
    int parteDecimal = flutuanteA->valorDecimal + flutuanteB->valorDecimal;
    if (soma->valorDecimal>=10000)
    {
        parteInteira++;
        parteDecimal -= 10000;
    }

    soma->valorInteiro = parteInteira;
    soma->valorDecimal = parteDecimal;
    return (soma);
}