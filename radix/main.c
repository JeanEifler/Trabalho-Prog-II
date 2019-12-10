#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "dados.h"
#define I_MAX 20

int main(){

    int linhas = 0, i;
    double tempo_r = 0, tempo_q = 0;
    clock_t clock_1, clock_2, clock_3;
    dado_t **dados;

    for(i = 0; i < I_MAX; i++)
    {
    	dados = ler_dados_csv("toy_dataset.csv", &linhas);
    	clock_1 = clock();
    	radix_sort(dados, &linhas);
    	clock_2 = clock();
    	tempo_r = tempo_r + ((double) (clock_2 - clock_1) / CLOCKS_PER_SEC);
    }

    tempo_r = tempo_r / I_MAX;
    printf("Media Radix = %f s\n", tempo_r);


    for(i = 0; i < I_MAX; i++)
    {
    	dados = ler_dados_csv("toy_dataset.csv", &linhas);
    	clock_2 = clock();
    	quick_sort(dados, 0, --linhas);
    	clock_3 = clock();
    	tempo_q = tempo_q + ((double) (clock_3 - clock_2) / CLOCKS_PER_SEC);
    }
    tempo_q = tempo_q / I_MAX;
    printf("Media Quick = %f s\n", tempo_q);
    //imprime_dados(dados, &linhas);
    liberar_dados(dados, &linhas);
    return 0;
}
