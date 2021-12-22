#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int fatores_a[50] = {};
int fatores_b[50] = {};


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

int decomposicao_a (int n, int cont, int i){

  //Parametros pra função
  int aux = 2; //Auxiliar
  int L;
  L = ceil(sqrt(cont));

  //Teste se é primo ou não.
  if (n == 1){
    fatores_a[i]= 1;
    return i;
  }
  else{
    if (n % primo (cont, L, aux) == 0){
      fatores_a[i]= cont;
      i++;
      return decomposicao_a ((n / cont), cont, i);
    }
    else{
      return decomposicao_a (n, cont +1, i);
    }
  }
}

int decomposicao_b (int n, int cont, int i){

  //Parametros pra função
  int aux = 2; //Auxiliar
  int L;
  L = ceil(sqrt(cont));

  //Teste se é primo ou não.
  if (n == 1){
    fatores_b[i]= 1;
    return i;
  }
  else{
    if (n % primo (cont, L, aux) == 0){
      fatores_b[i]= cont;
      i++;
      return decomposicao_b ((n / cont), cont, i);
    }
    else{
     return decomposicao_b (n, cont +1, i);
    }
  }
}

void resto_mmc (int mmc, int i_maior, int c1){
  if (c1 > i_maior){
    printf ("MMC : %d\n", mmc);
    return;
  }
  else{
    mmc *= fatores_a[c1];
    resto_mmc (mmc, i_maior, c1+1);
  }
}


void solucao (int i_maior, int c1, int i_menor,int c2, int mmc, int mdc){
  
  
  if (c2 > i_maior){
    
    resto_mmc (mmc, i_maior, c1);
    
    printf ("MDC : %d\n", mdc);
    return;
  }
  else{
    if (fatores_a[c1] == 1){
      mmc *= fatores_b[c2];
      c2++;
    }
    if (fatores_b[c2] == 1){
      mmc *= fatores_a[c1];
      c1++;
    }
 
    if (fatores_a[c1] == fatores_b[c2]){
      mmc *= fatores_a[c1];
      mdc *= fatores_a[c1];
      c1++;
      c2++;
      solucao (i_maior, c1, i_menor, c2, mmc, mdc);
    }
    else {

      if (fatores_a[c1] > fatores_b[c2]){
        mmc *= fatores_b[c2];
        
        c2++;
        solucao (i_maior, c1, i_menor, c2, mmc, mdc);
      }
      else{
        mmc *= fatores_a[c1];
        c1++;
        solucao (i_maior, c1, i_menor, c2, mmc, mdc);
      }
      return;
    }
    return;
  }
}


void resto_mmc_b (int mmc, int i_maior, int c1){
  if (c1 > i_maior){
    printf ("MMC : %d\n", mmc);
    return;
  }
  else{
    mmc *= fatores_b[c1];
    resto_mmc_b (mmc, i_maior, c1+1);
  }
}


void solucao_b (int i_maior, int c1, int i_menor,int c2, int mmc, int mdc){
  
  
  if (c2 > i_maior){
    resto_mmc_b (mmc, i_maior, c1);
    
    printf ("MDC : %d\n", mdc);
    return;
  }
  else{

    if (fatores_b[c1] == 1){
      mmc *= fatores_a[c2];
      c2++;
    }

    if (fatores_a[c2] == 1){
      mmc *= fatores_b[c1];
      c1++;
    }

    if (fatores_b[c1] == fatores_a[c2]){
      mmc *= fatores_b[c1];
      mdc *= fatores_b[c1];
      c1++;
      c2++;
      solucao_b (i_maior, c1, i_menor, c2, mmc, mdc);
    }
    else {
      if (fatores_b[c1] > fatores_a[c2]){
        mmc *= fatores_a[c2];
        c2++;
        solucao_b (i_maior, c1, i_menor, c2, mmc, mdc);
      }
      else{
        mmc *= fatores_b[c1];
        c1++;
        solucao_b (i_maior, c1, i_menor, c2, mmc, mdc);
      }
      return;
    }
    return;
  }
}

int main (){
  
  int a,b,r,i_a,i_b;
  int cont = 2; //Parametro da função de decomposição
  int i;

  for (i=0;i<50;i++){
    fatores_a[i] = 1;
    fatores_b[i] = 1;
  }
  i = 0;

  printf ("Digite dois números inteiros maiores que 1 para calcular MDC e MMC com base em seus fatores primos\n");
  
  scanf("%d %d",&a, &b);

  
  
  if (a >= 2 && b >= 2){
    i_a = decomposicao_a (a, cont, i);
    i_b = decomposicao_b (b, cont, i);
  

    if (i_a > i_b){
      solucao (i_a,0,i_b,0,1,1);
    }
    else if (i_b > i_a){
      solucao_b (i_b,0,i_a,0,1,1);
    }
    else {
      if (a > b){
        solucao_b (i_b,0,i_a,0,1,1);
      }
      else{
        solucao (i_a,0,i_b,0,1,1);
      }
    }

  
  }
  else{
    printf ("Digite números inteiro maiores que 1\n");
  }

  return 0;
}