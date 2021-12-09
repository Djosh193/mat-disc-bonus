#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int primo (int x, int L, int aux ){
  if (x <= 2){
    if (x == 2){
      return x;
    }
    else{
      return -x;
    }
  }
  else{
    
    if (aux > L){
      return x;
    }

    else{
      if (x % aux == 0){
        return -x;
      }
      return primo (x, L, aux+1);
    }
  }
}

void decomposicao (int n, int cont){

  //Parametros pra função
  int aux = 2; //Auxiliar
  int L;
  L = ceil(sqrt(cont));

  //Teste se é primo ou não.
  if (n == 1){
    printf("\n");
    return;
  }
  else{
    if (n % primo (cont, L, aux) == 0){
      printf("%d ", cont);
      decomposicao ((n / cont), cont);
    }
    else{
      decomposicao (n, cont +1);
    }
    return;
  }
  return;
}

int main (){
  
  int n; // Número para ser decomposto por fatores primos, != 1
  int cont = 2; //Contador

  scanf("%d", &n);
  
  if (n >= 2){
    decomposicao (n, cont);
  }

  return 0;
}