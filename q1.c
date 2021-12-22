#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void primo (int x, int L, int aux ){
  if (x <= 2){
    if (x == 2){
      printf ("%d É primo.\n", x);
      return;
    }
    else{
      printf ("%d Não é primo.\n", x);
      return;
    }
  }
  else{
    
    if (aux > L){
      printf ("%d É primo.\n", x);
      return;
    }

    else{
      if (x % aux == 0){
        printf ("%d Não é primo.\n", x);
        return;
      }
      primo (x, L, aux+1);
    }
  }
}

int main (){
  
  int x; //Número a ser testado se é primo ou não.
  int aux = 2; //Auxiliar
  int L; //Limite da busca

  printf ("Digite o número inteiro a ser testado se é primo ou não.\n");
  scanf("%d", &x);

  L = ceil(sqrt(x));

  primo (x, L, aux);

  return 0;
}