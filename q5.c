#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Algoritmo de Euclides
int MDC (int a, int b){
  if (a > b){
    if (a % b == 0){
      return b;
    }
    else {
      return MDC (b, a % b);
    }

  }
  else {
    if (b % a == 0){
      return a;
    }
    else {
      return MDC (a, b % a);
    }

  }

}

int main(){

  int a,b;

  printf ("Digite dois números inteiros para calcular seu MDC pelo Algoritmo de Euclides.\n");
  scanf("%d %d",&a, &b);

  if (a == 0){
    printf ("MDC (%d,%d) = %d\n", a, b, b );
  }
  else if (b == 0){
    printf ("MDC (%d,%d) = %d\n", a, b, a );
  }
  else{
    printf ("MDC (%d,%d) = %d\n", a, b, MDC(a,b) );
  }

  return 0;
}