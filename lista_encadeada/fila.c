#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int        valor; // conteudo do no
    struct no_ *prox; // prox no da lista
} no;

typedef struct {
    no *inicio;
    no *fim;
} fila;

fila *inicia_fila();
void insere(fila *f, int valor);
no *deleta(fila *f);
void exibe_fila(fila *f);

int main() {

    fila *f = inicia_fila();

    exibe_fila(f);

    insere(f, 1);
    insere(f, 5);
    insere(f, 50);

    exibe_fila(f);

    deleta(f);

    exibe_fila(f);

    deleta(f);
    deleta(f);

    exibe_fila(f);

    return 0;

}

fila *inicia_fila() {
    fila *tmp = malloc(sizeof(fila));

    tmp->inicio = NULL;
    tmp->fim = NULL;

    return tmp;
}

void insere(fila *f, int valor) {
    no *novo_no = malloc(sizeof(no));
    
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if (f->fim != NULL) {
        f->fim->prox = novo_no; 
    } else {
        f->inicio = novo_no;
    }

    f->fim = novo_no;
}

no *deleta(fila *f) {
    no *retorno = NULL;

    if (f->inicio != NULL) {
        retorno = f->inicio;
        f->inicio = f->inicio->prox;

        if (f->inicio == NULL) {
            f->fim = NULL;
        }
    }

    return retorno;
}

void exibe_fila(fila *f) {
    no *p = f->inicio;

    while (p != NULL) {
        printf("%d\t", p->valor);
        p = p->prox;
    }

    printf("\n");
}