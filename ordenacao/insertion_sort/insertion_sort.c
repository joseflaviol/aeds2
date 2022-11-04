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
    int i, j, chave;

    for (i = 1; i < tamanho_a; i++) {
        chave = a[i];
        j = i - 1;

        while (j > -1 && chave < a[j]) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = chave;
    }
}