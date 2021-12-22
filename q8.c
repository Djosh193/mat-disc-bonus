#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int unica (int s, int m){
  if (s > m){
    return s - m;
  }
  else {
    return unica ( s + m, m);
  }
}

void solucao (int s, int m, int m0, int i){
  if (s > m0){
    return;
  }
  else{
    printf ("Solução %d: %d\n", i, s);
    solucao (s + m, m, m0, i+1);
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
  int a, b, m, s, t, mdc;

  printf ("Calcular a solução de ax ≡ b mod m.\n");
  printf ("Digite os números inteiros a, b e m\n");
  scanf ("%d %d %d", &a, &b, &m);

  /*
  O inverso de a mod b, é y.a congruente 1 mod b
  ou seja, m | ( y.a - 1 )
  a tem q ser coprimo de b, e b > 1.

  A solução é de ax ≡ b mod m é:
  x = b. y
  */

  mdc = mdc_extendido (a, m, &s, &t);

  if (b % mdc == 0){

    if (mdc == 1){
      int x = (b * s) % m;
      int u = unica (x, m);

      printf ("Solução única (0 < x < %d ): %d\n",m, u);
      printf ("Solução geral: %d + %d.K\n", u, m);
    }
    else{
      //Vai ter mdc soluções
      a = a/mdc;
      b= b/mdc;
      int m0 = m;
      m = m/mdc;

      mdc = mdc_extendido (a, m, &s, &t);
       int x = (b * s) % m;
      int u = unica (x, m);

      printf ("As soluções (0 < x < %d) são:\n", m0);
      solucao (u, m, m0, 1);

    }
 
  }
  else {
    printf ("A congruência não tem solução.\n");
  }

  return 0;
}