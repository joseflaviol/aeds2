/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef PILHA_H
#define PILHA_H

#include "no.h"
#include "veiculo.h"

typedef struct {
    no *topo;
} Pilha;

/**
 * inicia uma pilha vazia
 * @return - ponteiro para pilha vazia
 */
Pilha *inicia_pilha();

/**
 * insere um novo nó na pilha
 * @param pilha - ponteiro para a pilha a ter o novo nó inserido
 * @param veiculo - valor que ficará salvo no novo nó
 */
void insere_pilha(Pilha *pilha, Veiculo *veiculo);

/**
 * operação de exclusão na pilha (remove o nó do topo)
 * @param pilha - ponteiro para a pilha a ter o topo removido
 * @return - ponteiro para o nó removido
 */
no *remove_pilha(Pilha *pilha);

#endif /* PILHA_H */

