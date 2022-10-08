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
    int *p, *q, *min, aux;

    for (p = a; p < a + tamanho_a; p++) {
        min = p;

        for (q = p + 1; q < a + tamanho_a; q++) {
            if (*q < *min) {
                min = q;
            }
        }

        aux = *min;
        *min = *p;
        *p = aux;
    }
}