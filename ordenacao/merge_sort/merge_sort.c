#include <stdio.h>
#include <stdlib.h>

int *inicializa(int tamanho);
void merge(int *a, int inicio, int meio, int fim);
void merge_sort(int *a, int inicio, int fim);

int main() {

    int *a = inicializa(10);

    printf("Estado inicial:\n");

    for (int i = 0; i < 10; i++) {
        printf("    %d", a[i]);
    }

    printf("\n");

    merge_sort(a, 0, 10);

    printf("Estado final:\n");

    for (int i = 0; i < 10; i++) {
        printf("    %d", a[i]);
    }

    printf("\n");

    return 0;

}

int *inicializa(int tamanho) {
    int i;
    int *a = (int *) malloc(sizeof(int) * tamanho);

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        a[i] = rand() % 100;
    }

    return a;
}

void merge(int *a, int inicio, int meio, int fim) {
    int *v = (int *) malloc(sizeof(int) * (fim - inicio));
    int i, j, k;

    for (k = 0, i = inicio, j = meio; i < meio && j < fim; k++) {
        if (a[i] < a[j]) {
            v[k] = a[i++];
        } else {
            v[k] = a[j++];
        }
    }

    while (i < meio) {
        v[k++] = a[i++];
    }

    while (j < fim) {
        v[k++] = a[j++];
    }

    for (i = inicio; i < fim; i++) {
        a[i] = v[i - inicio];
    }
}

void merge_sort(int *a, int inicio, int fim) {
    if (inicio < fim - 1) {
        int meio = (inicio + fim) / 2;
        merge_sort(a, inicio, meio);
        merge_sort(a, meio, fim);
        merge(a, inicio, meio, fim);
    }
}