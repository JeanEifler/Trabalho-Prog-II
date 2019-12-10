#ifndef DADO_H_INCLUDED

typedef struct dados dado_t;

dado_t * criar_dado (int number, char *city, char *gender, int age, float income, char *illness);
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas);
void liberar_dados (dado_t **vetor, int *n_linhas);
void imprime_dados (dado_t **vetor, int *n_linhas);
void radix_sort(dado_t **dados, int *linhas);

void quick_sort(dado_t **dados, int esq, int dir);
int med_tres(dado_t **dados, int esq, int dir);
int particao(dado_t **dados, int esq, int dir);
void swap(dado_t **dados, int i, int j);

#endif
