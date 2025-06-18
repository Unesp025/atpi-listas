#include <stdio.h>

/*
Sim, a main pode ser chamada recursivamente.
Ao executar o programa, a main é chamada
automaticamente pela primeira vez; Em seguida,
ao final da função, uma nova chamada acontece,
trazendo a execução da main novamente.
Se nenhum ponto de parada for definido, a execução
da main continuará acontecendo até exceder a
memória disponível no computador.
*/

int count = 0;

int main()
{
  count++;
  printf("%d\n", count);
  if (count == 10)
    return (0);
  main();
}
