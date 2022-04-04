#include "geracao.h"
//=============================================================================
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
//=============================================================================
// PROCEDIMENTO PARA TROCAR DOIS ELEMENTOS DO VETOR
void swap(uint64_t *i, uint64_t *j) {
   uint64_t temp = *i;
   *i = *j;
   *j = temp;
}

void swap2(uint64_t *i, uint64_t *j) {
   uint64_t temp = *i;
   *i = *j;
   *j = temp;
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM CRESCENTE
void crescente(uint64_t *v, uint64_t n) {
   for (uint64_t i = 0; i < n; i++) {
      v[i] = i;
   }
}

void crescente2(uint64_t *v, uint64_t n) {
   for (uint64_t i = 0; i < n; i++) {
      v[i] = i;
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM DECRESCENTE
void decrescente(uint64_t *v, uint64_t n) {
   for (uint64_t i = 0; i < n; i++) {
      v[i] = n - 1 - i;
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM ALEATORIA
void aleatorio(uint64_t *v, uint64_t n) {
   crescente2(v, n);
   srand(time(NULL));
   for (uint64_t i = 0; i < n; i++) {
      swap2(&v[i], &v[rand() % n]);
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS DA ENTRADA PADRAO
int entradaPadrao(int *v) {
   uint64_t n;
   scanf("%i", &n);
   v = (int*) malloc(n*sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%i", &v[i]);
   }
   return n;
}
//=============================================================================
// PROCEDIMENTO PARA EXIBIR OS DADOS PRESENTES NO ARRANJO
void mostrar(uint64_t *v, uint64_t n) {
   printf("[ ");
   for (uint64_t i = 0; i < n; i++) {
      printf("%d ", v[i]);
   }
   printf("] \n");
}
//=============================================================================
// PROCEDIMENTO PARA VERIFICAR SE O ARRANJO ESTA ORDENADO
bool isOrdenado(uint64_t *v, uint64_t n){
   bool resp = true;
   for(uint64_t i = 1; i < n; i++){
      if(v[i-1] > v[i]){
         i = n;
         resp = false;
      }
   }
   return resp;
}
//=============================================================================
