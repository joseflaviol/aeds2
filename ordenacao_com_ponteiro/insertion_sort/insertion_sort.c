#include <stdio.h>
#include <stdlib.h>

int *inicializa(int tamanho);
void insertion_sort(int *a, int tamanho_a);

int main() {

    int *a = inicializa(10);

    printf("Estado inicial:\n");

    for (int i = 0; i < 10; i++) {
        printf("    %d", a[i]);
    }

    printf("\n");

    insertion_sort(a, 10);

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

void insertion_sort(int *a, int tamanho_a) {
    int *p, *q, chave;

    for (p = a + 1; p < a + tamanho_a; p++) {
        chave = *p;
        q = p - 1;

        while (q >= a && chave < *q) {
            *(q + 1) = *q;
            q--;
        }

        *(q + 1) = chave;
    }
}