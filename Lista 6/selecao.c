#include "selecao.h"
//=============================================================================
void selecao(uint64_t *array, uint64_t n){
    uint64_t trocas=0, comp=0;
    for (uint64_t i = 0; i < (n - 1); i++) {
      uint64_t menor = i;
      for (uint64_t j = (i + 1); j < n; j++){
         comp++;
         if (array[menor] > array[j]){
            menor = j;
         }
      }
      trocas++;
      swap(&array[menor], &array[i]);
   }
   printf("Comp: %lu / Trocas: %lu ", comp, trocas);
}
//=============================================================================
