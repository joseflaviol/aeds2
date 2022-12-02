/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef LISTA_H
#define LISTA_H

#include "no.h"
#include "veiculo.h"

using namespace std;

typedef struct {
    no *inicio;
    int tamanho;
} Lista;

/**
 * inicia uma lista vazia
 * @return - ponteiro para a lista vazia
 */
Lista *inicia_lista();

/**
 * exibe os elementos da lista
 * @param veiculos - lista a ter os elementos exibidos
 */
void exibe(Lista *veiculos);

/**
 * insere um veículo na lista
 * @param veiculos - lista encadeada de veículos
 * @param veiculo - veículo a ser inserido na lista
 * @param ordenada - se true, significa que a lista é ordenada; falso caso o
 * contrário
 * @return 1, se for possível inserir, -1 caso não seja possível inserir
 */
int insere(Lista *veiculos, Veiculo *veiculo, bool ordenada);

/**
 * busca um veículo a partir de sua placa
 * @param veiculos - lista de veículos
 * @param ant - aponta para o nó anterior ao nó encontrado
 * @param pont - aponta para o nó encontrado, ou para nulo caso o veículo não
 * esteja na lista
 * @param placa - placa do veículo buscado
 */
void busca(Lista *veiculos, no **ant, no **pont, string placa);

/**
 * busca por um veículo em uma lista ordenada a partir das placas
 * @param veiculos_ordenados - lista ordenada
 * @param ant - ponteiro para o nó anterior ao resultado encontrado
 * @param pont - ponteiro para o nó encontrado, assume nulo se o item não
 * estiver na lista
 * @param placa - chave de busca
 */
void busca_ordenada(Lista *veiculos_ordenados, no **ant, no **pont, string placa);

/**
 * remove um nó da lista
 * @param veiculos - lista a ter o nó removido
 * @param ant - nó anterior ao nó a ser removido
 * @param pont - nó a ser removido
 * @return - valor que o nó guardava, que no caso é o veículo
 */
Veiculo *deleta(Lista *veiculos, no *ant, no *pont);

/**
 * remove todos os nós da lista
 * @param lista - lista a ter os nós removidos
 * @return - NULL
 */
Lista *encerra_lista(Lista *lista);

#endif /* LISTA_H */

