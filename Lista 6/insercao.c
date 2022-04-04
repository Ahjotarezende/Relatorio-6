#include "insercao.h"
//=============================================================================
void insercao(uint64_t *array, uint64_t n){
     uint64_t trocas=0, comp=0;
    for (uint64_t i = 1; i < n; i++) {
      uint64_t tmp = array[i];
      uint64_t j = i - 1;
      comp++;
      while ((j >= 0) && (array[j] > tmp)) {
         comp++;
         trocas++;
         array[j + 1] = array[j];
         if(j==0)
            break;
         j--;
      }
      trocas++;
      array[j+1] = tmp;
   }
   printf("Comp: %llu / Trocas: %llu ", comp, trocas);
}
//=============================================================================
