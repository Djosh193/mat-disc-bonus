#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// O tamanho dos Vetores é o tamanho máximo de N, se quiser N maiores, aumente o tamanho do vetor.
int rk [100] = {};
int mk [100] = {};
int MK [100] = {};
int sk [100] = {};

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

int pegando_M (int b, int a, int x){
  if (b == a){
    return x;
  }
  else{
    x *= mk[a];
    return pegando_M (b,a+1,x);
  }
}

void construindo_MK (int b, int a, int M){
  if (b == a){
    return;
  }
  else{
    MK[a] = M/mk[a];
    construindo_MK (b, a+1, M);
  }
}

int pegando_x0 (int b, int a, int x0){
  if (b == a){
    return x0;
  }
  else{
    x0 += MK[a]*sk[a]*rk[a];
    return pegando_x0 (b, a+1, x0);
  }
}

int main (){

  printf ("Programa para calcular a solução única de três congruências usando o Teorema Chinês do Resto\n");

  printf ("Congruências do tipo x ≡ r mod m.\n");
  printf ("Digite quantas congruências serão.\n");
  int N;
  scanf ("%d", &N);

  congruencia (N,0);

  int M;
  M = pegando_M (N,0,1);
  
  construindo_MK(N,0,M);

  pegando_sk (N,0);

  int x0;
  x0 = pegando_x0 (N,0,0);

  printf ("A solução no intervalo 0 < X0 < %d, é X0 = %d\n", M, x0 % M);
  

  return 0;
}