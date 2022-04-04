#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
//=============================================================================

double get_memory_used_MB() //fun��o responsavel por calcular a memoria gasta
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/(1024*1024);
}

void teste(uint64_t n, char ordem){

    //Delcaracao de variaveis
    double cpu_time_used, memory_used;
    size_t peakSize;
    uint64_t  *array = (uint64_t*) malloc(n*sizeof(uint64_t));

    // VARIAVEIS PARA CALCULAR O TEMPO
    clock_t inicio, fim;
    double total;


    //Geracao do conjunto a ser ordenado
    switch(ordem){
      case 'C': crescente2(array, n);
      break;
      case 'D': decrescente(array, n);
      break;
      case 'A':  aleatorio(array, n);
      break;
      default: aleatorio(array, n);
    }
    //Mostrar o conjunto a ser ordenado
	 //mostrar(array, n);


    //Execucao do algoritmo de ordenacao
    inicio = clock();
    //bolha(array, n);
    //countingsort(array, n);
    //heapsort(array, n);
    insercao(array, n);
    //mergesort(array, n);
    //quicksort(array, n);
    //selecao(array, n);
    //shellsort(array, n);
    fim = clock();
    memory_used = get_memory_used_MB();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);


    //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
    //algoritmo.mostrar(array, n);
    printf("/ Tempo: %f s / Valor de N: %d / Memoria: %0.2f MB\n", total, n, memory_used);
    //printf("isOrdenado: %s\n", isOrdenado(array, n) ? "true" : "false");

    //Desalocar o espaco de memoria do array
    free(array);

}


int main(int argc, char **argv) {
    printf("VETOR EM ORDEM CRESCENTE \n");
    for(uint64_t i=1000; i<=1024000; i=i*2){
        teste(i, 'C');
        //teste(i, 'D');
        //teste(i, 'A');
    }
    printf("\n\nVETOR EM ORDEM DECRESCENTE\n");
    for(uint64_t i=1000; i<=1024000; i=i*2){
        //teste(i, 'C');
        teste(i, 'D');
        //teste(i, 'A');
    }
    return 0;
}
