#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int        valor; // conteudo do no
    struct no_ *prox; // prox no da lista
} no;

typedef struct {
    no *topo;
} pilha;

pilha *inicia_pilha();
void insere(pilha *p, int valor);
no *deleta(pilha *p);
void exibe_pilha(pilha *p);

int main() {

    pilha *p = inicia_pilha();

    insere(p, 5);
    insere(p, 0);
    insere(p, 7);
    insere(p, 15);

    exibe_pilha(p);

    deleta(p);
    deleta(p);

    exibe_pilha(p);

    return 0;

}

pilha *inicia_pilha() {
    pilha *tmp = malloc(sizeof(pilha));

    tmp->topo = NULL;

    return tmp;
}

void insere(pilha *p, int valor) {
    no *novo_no = malloc(sizeof(no));

    novo_no->valor = valor;
    novo_no->prox = p->topo;
    
    p->topo = novo_no;
}

no *deleta(pilha *p) {
    no *retorno = NULL;

    if (p->topo != NULL) {
        retorno = p->topo;
        p->topo = p->topo->prox;    
    }

    return retorno;
}

void exibe_pilha(pilha *p) {
    no *q = p->topo;

    while (q != NULL) {
        printf("%d\t", q->valor);
        q = q->prox;
    }

    printf("\n");
}