#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


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
  scanf ("%d %d", &a, &b);

  mdc = mdc_extendido (a, b, &s, &t);
  printf ("MDC (a,b) = d = a.s + b.t\n");
  printf ("MDC (%d,%d) = %d = %d.%d + %d.%d\n",a, b, mdc, a, s, b, t);

  return 0;
}