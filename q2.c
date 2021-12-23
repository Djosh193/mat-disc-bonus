#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void primo(long long int x, long long int L) {
  int i;
  for(i = 2; i < L; i++) {
    if (x % i == 0) {
      return;
    }
  }
  printf("%lld\n", x);
}

int main (){
  printf ("Listar números Primos por 60 segundos:\n");

  long long int c = 2;
  int f = clock() / 1000;

  while (f < 61) {
    f = clock() / 1000;

    int aux = 2; //Auxiliar
    long long int L;
    L = ceil(sqrt(c));

    //Teste se é primo ou não.
    primo (c, L);
    
    c++;
  }

  return 0;
}