#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "dados.h"
#define I_MAX 1

int main(){

    int linhas = 0, i;
    double tempo = 0;
    clock_t clock_1, clock_2;
    dado_t **dados;

    for(i = 0; i < I_MAX; i++)
    {
    	dados = ler_dados_csv("camera_temp.csv", &linhas);
    	clock_1 = clock();
    	radix_sort(dados, &linhas);
    	clock_2 = clock();
    	tempo = tempo + ((double) (clock_2 - clock_1) / CLOCKS_PER_SEC);
    }
    tempo = tempo / 20;
    printf("Media = %f s\n", tempo);
    imprime_dados(dados, &linhas);
    liberar_dados(dados, &linhas);
    return 0;
}
