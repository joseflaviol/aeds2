/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */

#include <iostream>

#include "lista.h"

using namespace std;

/**
 * inicia uma lista vazia
 * @return - ponteiro para a lista vazia
 */
Lista *inicia_lista() {
    Lista *l = new Lista;
    
    l->inicio = new no;
    l->inicio->veiculo = NULL;
    l->inicio->proximo = NULL;
    l->tamanho = 0;
    
    return l;
}

/**
 * exibe os elementos da lista
 * @param veiculos - lista a ter os elementos exibidos
 */
void exibe(Lista *veiculos) {
    no *p = veiculos->inicio->proximo;
    
    while (p != NULL) {
        exibe_veiculo(p->veiculo);
        p = p->proximo;
    }
}

/**
 * insere um veículo na lista
 * @param veiculos - lista encadeada de veículos
 * @param veiculo - veículo a ser inserido na lista
 * @param ordenada - se true, significa que a lista é ordenada; falso caso o
 * contrário
 * @return 1, se for possível inserir, -1 caso não seja possível inserir
 */
int insere(Lista *veiculos, Veiculo *veiculo, bool ordenada) {
    int retorno = -1;
    
    no *ant;
    no *pont;
    
    if (ordenada) {
        busca_ordenada(veiculos, &ant, &pont, veiculo->placa);
    } else {
        busca(veiculos, &ant, &pont, veiculo->placa);
    }
    
    if (pont == NULL) {
        no *novo_no = new no;
        
        novo_no->veiculo = veiculo;
        novo_no->proximo = ant->proximo;
        
        ant->proximo = novo_no;
        
        veiculos->tamanho += 1;
        
        retorno = 1;
    }
    
    return retorno;
}

/**
 * busca um veículo a partir de sua placa
 * @param veiculos - lista de veículos
 * @param ant - aponta para o nó anterior ao nó encontrado
 * @param pont - aponta para o nó encontrado, ou para nulo caso o veículo não
 * esteja na lista
 * @param placa - placa do veículo buscado
 */
void busca(Lista *veiculos, no **ant, no **pont, string placa) {
    *ant = veiculos->inicio;
    *pont = NULL;
    no *ptr = veiculos->inicio->proximo;
    
    while (ptr != NULL) {
        if (ptr->veiculo->placa != placa) {
            *ant = ptr;
            ptr = ptr->proximo;
        } else {
            *pont = ptr;
            ptr = NULL;
        }
    }
}

/**
 * busca por um veículo em uma lista ordenada a partir das placas
 * @param veiculos_ordenados - lista ordenada
 * @param ant - ponteiro para o nó anterior ao resultado encontrado
 * @param pont - ponteiro para o nó encontrado, assume nulo se o item não
 * estiver na lista
 * @param placa - chave de busca
 */
void busca_ordenada(Lista *veiculos_ordenados, no **ant, no **pont, string placa) {    
    *ant = veiculos_ordenados->inicio;
    *pont = NULL;
    no *ptr = veiculos_ordenados->inicio->proximo;
    
    while (ptr != NULL) {
        if (ptr->veiculo->placa < placa) {
            *ant = ptr;
            ptr = ptr->proximo;
        } else {
            if (ptr->veiculo->placa == placa) {
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

/**
 * remove um nó da lista
 * @param veiculos - lista a ter o nó removido
 * @param ant - nó anterior ao nó a ser removido
 * @param pont - nó a ser removido
 * @return - valor que o nó guardava, que no caso é o veículo
 */
Veiculo *deleta(Lista *veiculos, no *ant, no *pont) {
    ant->proximo = pont->proximo;
    pont->proximo = NULL;
    veiculos->tamanho -= 1;
    return pont->veiculo;
}

/**
 * remove todos os nós da lista
 * @param lista - lista a ter os nós removidos
 * @return - NULL
 */
Lista *encerra_lista(Lista *lista) {
    no *ant = lista->inicio->proximo;
    no *pont = lista->inicio->proximo;
    
    while (ant != NULL) {
        pont = ant->proximo;
        delete(ant);
        ant = pont;
    }
    
    delete(lista);
    
    return NULL;
}