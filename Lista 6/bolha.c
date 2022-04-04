#include "geracao.h"
#include "bolha.h"
#include <stdio.h>
//=============================================================================
void bolha(uint64_t *array, uint64_t n){
    unsigned long long int i, j;
    unsigned long long int trocas=0, comp=0;
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {
        comp++;
         if (array[j] > array[j + 1]) {
           trocas++;
            swap2(&array[j], &array[j + 1]);
         }
      }
   }
   printf("Comp: %lu / Trocas: %lu ", comp, trocas);
}
//=============================================================================
