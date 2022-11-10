#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_ {
    int        chave; // campo identificador
    int        valor; // conteudo do no
    struct no_ *prox; // prox no da lista
} no;

no *inicia_lista();
void busca_encadeada(no *lista, no **ant, no **pont, int chave);
bool insere(no *lista, int chave, int valor);
no *deleta(no *lista, int chave);
void exibe_lista(no *lista);

int main() {

    no *lista = inicia_lista();

    insere(lista, 1, 5);
    insere(lista, 3, 15);
    insere(lista, 2, 0);
    insere(lista, 4, 50);

    exibe_lista(lista);

    deleta(lista, 2);

    exibe_lista(lista);

    return 0;

}

no *inicia_lista() {
    no *nova_lista = malloc(sizeof(no));

    nova_lista->valor = 0;
    nova_lista->prox = NULL;

    return nova_lista;
}

void busca_encadeada(no *lista, no **ant, no **pont, int chave) {
    no *ptr;

    *ant = lista;
    *pont = NULL;
    ptr = lista->prox;

    while (ptr != NULL) {
        if (ptr->chave < chave) {
            *ant = ptr;
            ptr = ptr->prox;
        } else {
            if (ptr->chave == chave) {
                *pont = ptr;
            }
            ptr = NULL;
        }
    }

}

bool insere(no *lista, int chave, int valor) {
    bool retorno = false;

    no *ant;
    no *pont;

    busca_encadeada(lista, &ant, &pont, chave);

    if (pont == NULL) {
        no *novo_no = malloc(sizeof(no));

        novo_no->chave = chave;
        novo_no->valor = valor;

        novo_no->prox = ant->prox;
        ant->prox = novo_no;

        retorno = true;    
    }

    return retorno;
}

no *deleta(no *lista, int chave) {
    no *retorno = NULL;

    no *ant;
    no *pont;

    busca_encadeada(lista, &ant, &pont, chave);

    if (pont != NULL) {
        ant->prox = pont->prox;
        retorno = pont;
    }

    return retorno;
}

void exibe_lista(no *lista) {
    no *p = lista->prox;

    while (p != NULL) {
        printf("lista[%d] = %d\n", p->chave, p->valor);
        p = p->prox;
    }
}