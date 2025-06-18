#include <stdio.h>

/*
Sim, a main pode ser chamada recursivamente.
Ao executar o programa, a main e chamada   
*/
 
int count = 0;

int main()
{
  count++;
  printf("%d", count);
  if (count == 10)
    return (0);
  main();
}
