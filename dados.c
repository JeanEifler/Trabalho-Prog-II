#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

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


dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
	int 	number;
	char	city[32];
	char	gender[8];
	int		age;
	float	income;
	char	illness[4];

	char 	pula_linha[64];
	int		i = 0, linhas = 0;
    dado_t 	**dados;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    fgets(pula_linha, 64, fp);

    while (fgets(pula_linha, 64, fp) != NULL){
        linhas++;
    }

    dados = malloc(sizeof(struct dado *) * linhas);

    rewind(fp);
    fgets(pula_linha, 64, fp);


    while (fscanf (fp, "%d,%31[^,],%7[^,],%d, %f, %3[^\n]", &number, city, gender, &age, &income, illness) == 6){
        dados[i] = criar_dado(number, city, gender, age, income, illness);
        i++;
    }

    *n_linhas = i;
    fclose (fp);
    return dados;
}

void imprime_dados (dado_t **vetor, int *n_linhas)
{
    int i=0;
    while (i < *n_linhas)
    {
   	    printf ("%d\n", vetor[i]->age);
        i++;
    }
}

void liberar_dados (dado_t **vetor, int *n_linhas){
    int i;
    for(i = 0; i < *n_linhas; i++)
    {
    	free(vetor[i]);
    }
    free (vetor);
}

void radix_sort(dado_t **dados, int *linhas){
    int i;
    int *b;
    int maior = dados[0]->age;
    int exp = 1;

    b = (int *)calloc(*linhas, sizeof(int));

    for (i = 0; i < *linhas; i++) {
        if (dados[i]->age > maior)
    	    maior = dados[i]->age;
    }

    while (maior/exp > 0) {
            int caixa[10] = { 0 };
        	for (i = 0; i < *linhas; i++)
        	    caixa[(dados[i]->age / exp) % 10]++;

        	for (i = 1; i < 10; i++)
        	    caixa[i] += caixa[i - 1];

        	for (i = *linhas - 1; i >= 0; i--)
        	    b[--caixa[(dados[i]->age / exp) % 10]] = dados[i]->age;

        	for (i = 0; i < *linhas; i++)
        	    dados[i]->age = b[i];

        	exp *= 10;
        }

    free(b);
}


void quick_sort(dado_t **dados, int esq, int dir)
{
	int p;
	if(esq < dir){
		p = particao(dados, esq, dir);
		quick_sort(dados, esq, p);
		quick_sort(dados, p+1, dir);
	}
}

int med_tres(dado_t **dados, int esq, int dir)
{
	int med;

	med = (esq + dir) / 2;

	if(dados[dir]->age < dados[esq]->age)
		swap(dados, esq, dir);

	if(dados[med]->age < dados[esq]->age)
		swap(dados, med, esq);

	if(dados[dir]->age < dados[med]->age)
		swap(dados, dir, med);

	return med;
}
int particao(dado_t **dados, int esq, int dir)
{

	int med = med_tres(dados, esq, dir);
	dado_t *pivot = dados[med];
	int i = esq - 1;
	int j = dir + 1;

	for(;;){
		do{
			i = i + 1;
		}while(dados[i]->age < pivot->age);
		do{
			j = j - 1;
		}while(dados[j]->age > pivot->age);

		if(i >= j)
			return j;
		swap(dados, i, j);
	}
	return j;
}

void swap(dado_t **dados, int i, int j)
{
	dado_t *temp = dados[i];
	dados[i] = dados[j];
	dados[j] = temp;
}
