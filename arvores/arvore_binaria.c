#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *esq;
    struct reg *dir;
} No;

typedef struct {
    No *raiz;
} ArvoreBinaria;

void inicia_arvore_binaria(ArvoreBinaria **a);
void insere(ArvoreBinaria *a, int info);
void pre_ordem(No *no);
void em_ordem(No *no);
void pos_ordem(No *no);
void visita(No *no);

int main() {

    ArvoreBinaria *a;

    inicia_arvore_binaria(&a);

    insere(a, 6);
    insere(a, 4);
    insere(a, 5);
    insere(a, 3);
    insere(a, 8);
    insere(a, 7);
    insere(a, 9);

    printf("pre ordem:\n");
    pre_ordem(a->raiz);
    printf("\n");

    printf("em ordem:\n");
    em_ordem(a->raiz);
    printf("\n");

    printf("pos ordem:\n");
    pos_ordem(a->raiz);
    printf("\n");

    return 0;

}

void inicia_arvore_binaria(ArvoreBinaria **a) {
    *a = malloc(sizeof(ArvoreBinaria));

    (*a)->raiz = NULL;
}

void insere(ArvoreBinaria *a, int info) {
    if (a->raiz == NULL) {
        a->raiz = malloc(sizeof(No));
        a->raiz->info = info;
        a->raiz->esq = NULL;
        a->raiz->dir = NULL;
        return;
    }

    No *aux = a->raiz;

    while (1) {
        if (aux->info > info) {
            if (aux->esq != NULL) {
                aux = aux->esq;
            } else {
                aux->esq = malloc(sizeof(No));
                aux->esq->info = info;
                aux->esq->esq = NULL;
                aux->esq->dir = NULL;
                break;
            }
        } else {
            if (aux->dir != NULL) {
                aux = aux->dir;
            } else {
                aux->dir = malloc(sizeof(No));
                aux->dir->info = info;
                aux->dir->esq = NULL;
                aux->dir->dir = NULL;
                break;
            }
        }
    }
}

void pre_ordem(No *no) {
    visita(no);
    if (no->esq != NULL) pre_ordem(no->esq);
    if (no->dir != NULL) pre_ordem(no->dir);
}

void em_ordem(No *no) {
    if (no->esq != NULL) em_ordem(no->esq);
    visita(no);
    if (no->dir != NULL) em_ordem(no->dir);
}

void pos_ordem(No *no) {
    if (no->esq != NULL) pos_ordem(no->esq);
    if (no->dir != NULL) pos_ordem(no->dir);
    visita(no);
}

void visita(No *no) {
    printf("%d\t", no->info);
}