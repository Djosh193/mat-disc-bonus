#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Algoritmo de Euclides
void MDC (int a, int b){

  if (a % b == 0){
    printf ("MDC : %d\n", b);
    return;
  }

else {
    MDC (b, a % b);
    return;
  }

}

int main(){

  int a,b, aux;

  scanf("%d %d",&a, &b);

  if (a < b){
    aux = b;
    b = a;
    a = aux;
  }

  if ( b== 0){
    printf ("MDC :  d\n", a);
    return 0;
  }

  MDC(a,b);

  return 0;
}