#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Algoritmo de Euclides
void MDC (int a, int b, int t, int a0, int b0){
  
  if (a % b == 0){
    int s;
    s = (b - (b0 * t) )/a0;
    printf ("coeficiente s: %d\n",s);
    printf ("coeficiente t: %d\n",t);
    printf ("%d = %d.%d + %d.%d\n", b, a0, s, b0, t);
    return;
  }
  else {
    t = t + ( (a - (a%b))/b  );
    MDC (b, a % b, t, a0, b0);
    return;
  }

}

int main(){

  int a,b,s,aux;
  int t = 0;

  scanf("%d %d",&a, &b);
  if (a < b){
    aux = b;
    b = a;
    a = aux;
  }

  if ( b== 0){
    s = 1;
    printf ("coeficiente s: %d\n",s);
    printf ("coeficiente t: %d\n",t);
    printf ("%d = %d.%d + %d.%d\n", a, a, s, b, t);
    return 0;
  }

  printf ("MDC(%d,%d) = %d.s + %d.t\n",a,b,a,b);

  MDC(a,b,t,a,b);

  return 0;
}