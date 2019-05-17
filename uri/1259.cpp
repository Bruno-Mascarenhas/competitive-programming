#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int comp1(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int comp2(const void *a, const void *b){
  return -(*(int*)a - *(int*)b);
}

int main(void) {
  int n, x;
  scanf("%d", &n);
  int par[n+1], impar[n+1],p=0,i=0;

  for(int j=0; j<n; j++){
    scanf("%d", &x);
    if(x%2==0)
      par[p++] = x;
    else
      impar[i++] = x;
  }

  qsort(par,p,sizeof(int),comp1);
  qsort(impar,i,sizeof(int),comp2);

  for(int j=0; j<p;j++)
    printf("%d\n",par[j]);
  for(int j=0; j<i; j++)
    printf("%d\n",impar[j]);

  return 0;
}