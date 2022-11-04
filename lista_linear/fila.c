#include <stdio.h>
#include <stdlib.h>

int *fila;
int inicio;
int fim;
int M;

void inicia_fila(int tamanho);
void exibe_fila();
int insere(int no);
int *deleta();
void esvazia();

int main() {

    inicia_fila(10);

    insere(50);
    insere(10);
    insere(13);

    exibe_fila();

    deleta();

    exibe_fila();

    esvazia();

    exibe_fila();

    return 0;

}

void inicia_fila(int tamanho) {
    M = tamanho;
    fila = (int *) malloc(sizeof(int) * M);
    inicio = -1;
    fim = inicio;
}

void exibe_fila() {
    if (inicio == -1) {
        printf("\n\tFila vazia\n\n");
        return;
    }

    int i;
    
    for (i = inicio; i != fim + 1; i = (i + 1) % M) {
        printf("\tfila[%d] = %d\n", i, fila[i]);
    }

    printf("\n");
}

int insere(int no) {
    int retorno = -1;
    int aux = (fim + 1) % M;
    
    if (aux != inicio) {
        fim = aux;
        fila[fim] = no;
        retorno = fim;
        if (inicio == -1) {
            inicio = 0;
        }
    }

    return retorno;
}

int *deleta() {
    int *retorno = NULL;

    if (inicio != -1) {
        retorno = &fila[inicio];
        if (inicio == fim) {
            inicio = -1;
            fim = inicio;
        } else {
            inicio = (inicio + 1) % M;
        }
    }

    return retorno;
}

void esvazia() {
    inicio = -1;
    fim = inicio;
    M = 0;
    free(fila);
}