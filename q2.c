#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void primo (int x, int L, int aux ){
  if (x <= 2){
    if (x == 2){
      printf ("%d\n", x);
      return;
    }
    else{
      return;
    }
  }
  else{
    
    if (aux > L){
      printf ("%d\n", x);
      return;
    }

    else{
      if (x % aux == 0){
        return;
      }
      primo (x, L, aux+1);
    }
  }
}

void lista (int limite, int cont){
  //Parametros pra função
  int aux = 2; //Auxiliar
  int L;
  L = ceil(sqrt(cont));

  //Teste se é primo ou não.
  if (cont == limite){
    primo (cont, L, aux);
    return;
  }
  else{
    primo (cont, L, aux);
    lista (limite, cont+1);
  }
  return;
}

int main (){
  
  int limite; //Número limite da busca por primos
  int cont = 0; //Contador

  scanf("%d", &limite);

  lista (limite, cont);

  return 0;
}