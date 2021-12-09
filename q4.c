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

  int a,b,r;

  scanf("%d %d",&a, &b);

  r = MDC(a,b);
  printf ("MDC: %d\n", r);
  printf ("MMC: %d\n", ( a * b ) / r);

  return 0;
}