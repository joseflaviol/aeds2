#include <stdio.h>
#include <stdlib.h>

int *inicializa(int tamanho);
void selection_sort(int *a, int tamanho_a);

int main() {

    int *a = inicializa(10);

    printf("Estado inicial:\n");

    for (int i = 0; i < 10; i++) {
        printf("    %d", a[i]);
    }

    printf("\n");

    selection_sort(a, 10);

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

void selection_sort(int *a, int tamanho_a) {
    int i, j, min, aux;

    for (i = 0; i < tamanho_a; i++) {
        min = i;

        for (j = i + 1; j < tamanho_a; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
}