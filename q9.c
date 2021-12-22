#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rk [3] = {};
int mk [3] = {};
int MK [3] = {};
int sk [3] = {};

int unica (int s, int m){
  if (s > m){
    return s - m;
  }
  else {
    return unica ( s + m, m);
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


void congruencia (int fim, int inicio){

  if (inicio == fim){
    return;
  }
  else{
    printf ("Digite os números inteiros r%d m%d\n", inicio+1, inicio+1);
    scanf ("%d %d", &rk[inicio], &mk[inicio]);
    congruencia (fim, inicio+1);
  }
}

int calculo (int a, int b, int m){

  int mdc, s, t;
  mdc = mdc_extendido (a, m, &s, &t);
  int x = (b * s) % m;
  int u = unica (x, m);
  return u;
}

void  pegando_sk (int end, int start){
  
  if (start == end){
    return;
  }

  else{
    sk[start] = calculo (MK[start],1, mk[start]);
    pegando_sk (end, start+1);
  }
}

int main (){

  printf ("Programa para calcular a solução única de três congruências usando o Teorema Chinês do Resto\n");

  printf ("Congruências do tipo x ≡ r mod m.\n");

  congruencia (3,0);

  int M = mk[0] * mk[1] *mk[2] ;
  MK[0] = M/mk[0];
  MK[1] = M/mk[1];
  MK[2] = M/mk[2];  

  pegando_sk (3,0);

  int x0 = MK[0]*sk[0]*rk[0] + MK[1]*sk[1]*rk[1] + MK[2]*sk[2]*rk[2];

  printf ("A solução no intervalo 0 < X0 < %d, é X0 = %d\n", M, x0 % M);
  

  return 0;
}