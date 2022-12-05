#include <stdio.h>
#include <stdlib.h>

typedef struct _minHeap {
    int tamanho;
    int capacidade;
    int *heap;
} MinHeap;

MinHeap *inicia_min_heap(int capacidade);
int pai(int i);
int esquerda(int i);
int direita(int i);
int insere(MinHeap *minHeap, int chave);
int extrai_minimo(MinHeap *minHeap);

int main() {

    int i;
    MinHeap *minHeap = inicia_min_heap(10);

    srand(time(NULL));

    for (i = 0; i < minHeap->capacidade; i++) {
        insere(minHeap, rand() % 1000);
    }

    for (i = 0; i < minHeap->tamanho; i++) {
        printf("%d ", minHeap->heap[i]);
    }

    puts("");

    while (minHeap->tamanho != 0) { 
        printf("Extraido: %d\n", extrai_minimo(minHeap));
    }

    return 0;
}

MinHeap *inicia_min_heap(int capacidade) {
    MinHeap *minHeap = (MinHeap *) malloc(sizeof(MinHeap));

    minHeap->capacidade = capacidade;
    minHeap->heap = (int *) malloc(sizeof(int) * capacidade);
    minHeap->tamanho = 0;

    return minHeap;
}

int pai(int i) {
    return (i - 1) / 2;
}

int esquerda(int i) {
    return (2 * i) + 1;
}

int direita(int i) {
    return (2 * i) + 2;
}

int insere(MinHeap *minHeap, int chave) {
    if (minHeap->tamanho == minHeap->capacidade) {
        return -1;
    }

    int i, aux;

    minHeap->tamanho += 1;
    i = minHeap->tamanho - 1;
    minHeap->heap[i] = chave;

    while (i != 0 && minHeap->heap[pai(i)] > minHeap->heap[i]) {
        aux = minHeap->heap[pai(i)];
        minHeap->heap[pai(i)] = minHeap->heap[i];
        minHeap->heap[i] = aux;

        i = pai(i);    
    }

    return 1;
}

int extrai_minimo(MinHeap *minHeap) {
    if (minHeap->tamanho == 0) {
        return -1; // underflow
    }

    if (minHeap->tamanho == 1) {
        minHeap->tamanho = 0;
        return minHeap->heap[0];
    }

    int retorno = minHeap->heap[0];
    int i, aux, menor;

    i = 0;

    minHeap->heap[i] = minHeap->heap[minHeap->tamanho - 1];
    minHeap->tamanho -= 1;

    while (1) {
        menor = i;

        if (esquerda(i) < minHeap->tamanho && minHeap->heap[esquerda(i)] < minHeap->heap[i]) {
            menor = esquerda(i);
        }

        if (direita(i) < minHeap->tamanho && minHeap->heap[direita(i)] < minHeap->heap[menor]) {
            menor = direita(i);
        }

        if (menor == i) {
            break;
        }

        aux = minHeap->heap[menor];
        minHeap->heap[menor] = minHeap->heap[i];
        minHeap->heap[i] = aux;

        i = menor;
    }

    return retorno;
}