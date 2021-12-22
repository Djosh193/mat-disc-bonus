#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int unica (int s, int b){
  if (s > b){
    return s - b;
  }
  else {
    return unica ( s + b, b);
  }
}


int mdc_extendido (int a, int b, int *s, int *t){
  if (a == 0){
    *s = 0;
    *t = 1;
    return b;
  }
  int s1, t1;

  int MDC = mdc_extendido (b%a, a, &s1, &t1);
  *s = t1 - ( b / a ) * s1;
  *t = s1;

  return MDC;
}

int main (){
  int a, b, s, t, mdc;

  printf ("Calcular o inverso de a mod b.\n");
  printf ("Digite os números inteiros a e b\n");
  scanf ("%d %d", &a, &b);

  /*
  O inverso de a mod b, é x.a congruente 1 mod b
  ou seja, m | ( x.a - 1 )
  a tem q ser coprimo de b, e b > 1.
  */

  mdc = mdc_extendido (a, b, &s, &t);

  if (mdc == 1){
    int u = unica (s, b);
    printf ("%d é inverso de %d mod %d.\n", s, a, b);
    printf ("Solução única (0 < x < %d ): %d\n",b, u);
    printf ("Solução geral: %d + %d.K\n", s, b);
  }
  else {
    printf ("Não tem inverso.\n");
  }

  return 0;
}