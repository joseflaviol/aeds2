#include <stdio.h>
#include <stdlib.h>

int tamanhoLista;
int *lista;

int *iniciaLista(int tamanho); // retorna um array de "tamanho" elementos ordenados
int busca_binaria(int x); // retorna a posição onde x foi encontrado, ou -1 caso x não esteja na lista
void exibeLista();

int main() {

    int op = 0;
    int tamanho = 0;
    int x, posicao;
    
    while (op != 4) {
        printf("Menu:\n");
        printf("\t1 - Iniciar lista\n");
        printf("\t2 - Exibir lista\n");
        printf("\t3 - Buscar elemento\n");
        printf("\t4 - Sair\n");
        printf("sua escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            while (tamanho <= 0) {
                printf("tamanho da lista: ");
                scanf("%d", &tamanho);
            }

            tamanhoLista = tamanho;
            tamanho = 0;
            lista = iniciaLista(tamanhoLista + 1);
        } else if (op == 2) {
            exibeLista();
        } else if (op == 3) {
            printf("elemento a ser buscado: ");
            scanf("%d", &x);

            posicao = busca_binaria(x);

            if (posicao == -1) {
                printf("%d nao esta na lista\n", x);
            } else {
                printf("%d esta na posicao %d da lista\n", x, posicao);
            }
        } else if (op == 4) {
            printf("Ate mais\n");
        } else {
            printf("opcao invalida\n");
        }
    }

    return 0;
}

int *iniciaLista(int tamanho) {
    int i;
    int *novaLista = malloc(sizeof(int) * tamanho);

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        novaLista[i] += i == 0 ? 0 : novaLista[i - 1] + rand() % 100;
    }

    return novaLista;
}

int busca_binaria(int x) {
    int inferior = 0;
    int superior = tamanhoLista - 1;
    int meio;
    int posicao = -1;

    while (inferior <= superior) {
        meio = (inferior + superior) / 2;

        if (lista[meio] == x) {
            posicao = meio;
            inferior = superior + 1;
        } else if (lista[meio] < x) {
            inferior = meio + 1;
        } else {
            superior = meio - 1;
        }
    }

    return posicao;
}

void exibeLista() {
    int i;

    printf("Lista:\n");
    for (i = 0; i < tamanhoLista; i++) {
        printf("\tlista[%d] = %d\n", i, lista[i]);
    }
}