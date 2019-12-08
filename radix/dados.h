#ifndef DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char *city, char *gender, int age, float income, char *illness);
fila_t *ler_dados_csv_fila(char *nome_do_arquivo);
void liberar_dados(dado_t **vetor, int *n_linhas);
void liberar_dados_fila(fila_t *fila);
void radix_sort(dado_t **dados, int *linhas);

/* Outras funções aqui: fazer os comentários */




#endif
