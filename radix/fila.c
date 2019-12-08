#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *lista;
};


//cria uma pilha generica
fila_t * cria_fila (void)
{
    fila_t *p_fila = malloc(sizeof(fila_t));

    if(p_fila == NULL){
        perror("cria_fila: ");
        exit(EXIT_FAILURE);
    }
    criar_lista_enc();
    return p_fila;
}

//adiciona elemento na cauda
void enqueue(void* dado, fila_t *fila)
{
	no_t *no;

    if (fila == NULL) {
        fprintf(stderr, "enqueue: pilha invalida\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    printf("enqueue: %x\n", dado);
    #endif // DEBUG

    no = criar_no(dado);
    add_cauda(fila->lista, no);
}

void libera_fila(fila_t* fila)
{
    liberar_dados(fila);
    free (fila);
}


void *dequeue(fila_t *fila)
{
	no_t *no;
	void *dado;

    if (fila == NULL){
        fprintf(stderr, "dequeue: fila invalida!\n");
        exit(EXIT_FAILURE);
    }

    no = remover_cabeca(fila->lista);
    dado = obter_dado(no);
    free(no);

    return dado;
}

int fila_vazia(fila_t *fila)
{
	return lista_vazia(fila->lista);
}

