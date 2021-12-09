#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Algoritmo de Euclides
void MDC (int a, int b){
  if (a > b){
    if (a % b == 0){
      printf ("%d\n", b);
      return;
    }
    else {
      MDC (b, a % b);
    }

  }
  else {
    if (b % a == 0){
      printf ("%d\n", a);
      return;
    }
    else {
      MDC (a, b % a);
    }

  }

}

int main(){

  int a,b;

  scanf("%d %d",&a, &b);

  MDC(a,b);

  return 0;
}