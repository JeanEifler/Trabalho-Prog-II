#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "dados.h"

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

no_t *obter_cauda(lista_enc_t *lista){
    return lista->cauda;
}

void add_cabeca(lista_enc_t *lista, no_t* elemento){
    if (lista->tamanho == 0)
    {
        #ifdef DEBUG
        printf("add_cabeca: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG
        
        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
    }
    else {
        criar_no(elemento);
        ligar_nos(lista->cabeca, elemento);
        lista->cabeca = elemento;
        lista->tamanho++;
    }
        
}

no_t *remover_cauda(lista_enc_t *lista){
    if(lista->tamanho == 0){
        fprintf(stderr,"lista de tamanho zero");
        exit(EXIT_FAILURE);
    }
    no_t    *p_no = obter_cabeca(lista);    //corresponde a nova cauda
    no_t    *p_prox = obter_proximo(p_no);  //corresponde a antiga cauda
    while(p_prox != NULL){
        p_no = p_prox;
        p_prox = obter_proximo(p_no);
    }
    lista->cauda = p_no;
    desligar_no(p_no);
    libera_cauda(p_prox);
}

int lista_vazia(lista_enc_t* lista){
    fprintf(stderr, "pop() em pilha vazia!\n");
    return lista->tamanho;
}

fila_t *obter_lista(fila_t *fila){
    return fila->lista;
}

void libera_cauda(no_t *p_no){
	dado_t *p_dado = obter_dado (p_no);
    free(p_dado);
    free(p_no);
}
