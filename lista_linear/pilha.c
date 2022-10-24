#include <stdio.h>
#include <stdlib.h>

int *pilha;
int topo;
int M;

void inicia_pilha(int tamanho);
void exibe_pilha();
int insere(int no);
int *deleta();
void esvazia();

int main() {

    inicia_pilha(10);

    insere(50);
    insere(10);
    insere(13);

    exibe_pilha();

    deleta();

    exibe_pilha();

    esvazia();

    exibe_pilha();

    return 0;

}

void inicia_pilha(int tamanho) {
    M = tamanho;
    pilha = (int *) malloc(sizeof(int) * M);
    topo = -1;
}

void exibe_pilha() {
    if (topo == -1) {
        printf("\n\tPilha vazia\n\n");
        return;
    }

    int i;
    
    for (i = 0; i < topo + 1; i++) {
        printf("\tpilha[%d] = %d\n", i, pilha[i]);
    }

    printf("\n");
}

int insere(int no) {
    int retorno = -1;

    if (topo + 1 != M) {
        topo = topo + 1;
        pilha[topo] = no;
        retorno = topo;
    }

    return retorno;
}

int *deleta() {
    int *retorno = NULL;

    if (topo != -1) {
        retorno = &pilha[topo];
        topo = topo - 1;
    }

    return retorno;
}

void esvazia() {
    topo = -1;
    M = 0;
    free(pilha);
}