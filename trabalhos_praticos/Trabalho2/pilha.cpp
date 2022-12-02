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

#include "pilha.h"

using namespace std;

/**
 * inicia uma pilha vazia
 * @return - ponteiro para pilha vazia
 */
Pilha *inicia_pilha() {
    Pilha *p = new Pilha;
    
    p->topo = NULL;
    
    return p;
}

/**
 * insere um novo nó na pilha
 * @param pilha - ponteiro para a pilha a ter o novo nó inserido
 * @param veiculo - valor que ficará salvo no novo nó
 */
void insere_pilha(Pilha *pilha, Veiculo *veiculo) {
    no *novo_no = new no;
    
    novo_no->veiculo = veiculo;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

/**
 * operação de exclusão na pilha (remove o nó do topo)
 * @param pilha - ponteiro para a pilha a ter o topo removido
 * @return - ponteiro para o nó removido
 */
no *remove_pilha(Pilha *pilha) {
    no *retorno = NULL;
    
    if (pilha->topo != NULL) {
        retorno = pilha->topo;
        pilha->topo = pilha->topo->proximo;
    }
    
    return retorno;
}


