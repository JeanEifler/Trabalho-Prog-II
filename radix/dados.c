#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "dados.h"

//criar_dado alterar entradas
//fila_t *ler_dados_csv_fila, qual retorno e o que passar para função? é fila mesmo ou é igual as outras ordenações trabalhados?

//melhor ordenação vai ser com float
struct dados {
	int 	number;
	char	city[32];
	char	gender[8];
	int		age;
	float	income;
	char	illness[4];
};


dado_t * criar_dado (int number, char *city, char *gender, int age, float income, char *illness){
    
	dado_t * meu_novo_dado = malloc(sizeof(dado_t));

    if(meu_novo_dado == NULL){
        perror("error malocc");
        exit(EXIT_FAILURE);
    }
    
    meu_novo_dado->number = number;
    strncpy(meu_novo_dado->city, city, 32);
    strncpy(meu_novo_dado->gender, gender, 8);
    meu_novo_dado->age = age;
    meu_novo_dado->income = income;
    strncpy(meu_novo_dado->illness, illness, 4);

    return meu_novo_dado;
}


dado_t **ler_dados_csv_fila(char *nome_do_arquivo, int *n_linhas){
	int 	number;
	char	city[32];
	char	gender[8];
	int		age;
	float	income;
	char	illness[4];

	int		i = 0, linhas = 0;
    dado_t 	**dados;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    //fila = cria_fila();
    fgets(city, 32, fp);

    while (fgets(city, 32, fp) != NULL){
        linhas++;
    }

    dados = malloc(sizeof(struct dado *) * linhas);

    rewind(fp);
    fgets(city, 32, fp);


    while (fscanf (fp, "%d,%31[^\n],%7[^\n],%d, %f, %3[^\n]", &number, city, gender, &age, &income, illness) == 6){
        printf("Lido %d,%31[^\n],%7[^\n],%d, %f, %3[^\n]\n", &number, city, gender, &age, &income, illness);
        /* Cria um novo dado abstrato e armazena a sua referÃªncia */
        dados[i] = criar_dado(number, city, gender, age, income, illness);
        //enqueue(dado, fila);
        i++;
    }
    fclose (fp);

    *n_linhas = i;
    //return fila;
    return dados;
}

void liberar_dados(dado_t **vetor, int *n_linhas){
    int i;
    for(i = 0; i < *n_linhas; i++)
    {
        //printf("dado [%d] liberado!\n", i);
    	free(vetor[i]);
    }
    free (vetor);
}

void liberar_dados_fila(fila_t *fila){
    lista_enc_t *ptr_lista = obter_lista(fila);
    no_t        *ptr_no_ant;
    no_t        *ptr_no_prox = obter_cabeca(ptr_lista);
    dado_t      *ptr_dado;
    while(ptr_no_prox){
        ptr_dado = obter_dado (ptr_no_prox);
        free (ptr_dado);
        ptr_no_ant = ptr_no_prox;
        ptr_no_prox = obter_proximo(ptr_no_prox);
        free(ptr_no_ant);
    }
    free (ptr_lista);
}

void radix_sort(dado_t **dados, int *linhas){

    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    large = maior(dados, linhas);

    while(large > 0)
    {
        NOP++;
        large/=10;
    }

    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < linhas; i++)
        {
            remainder = (dados[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = dados[i];
            bucket_count[remainder] += 1;
        }

        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                dados[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
}

//CUIDADO COM A VARIAVEL LARGE, NÃO É FLOAT
int maior(dado_t **dados, int n){

        int large = dados[0]->age, i;
        for(i = 1; i < n; i++)
        {
            if(large < dados[i]->age)
                large = dados[i]->age;
        }
        return large;
}
