/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */
#ifndef FILA_H
#define FILA_H

#include "no.h"
#include "veiculo.h"

typedef struct {
    no *inicio;
    no    *fim;
} Fila;

/**
 * inicia uma fila vazia
 * @return - ponteiro para fila inciada
 */
Fila *inicia_fila();

/**
 * cria um novo nó que aponta para o veículo, e insere o nó na fila
 * @param fila - ponteiro para a fila onde o nó será inserido
 * @param veiculo - ponteiro para o veículo que será apontado pelo novo nó
 */
void insere_fila(Fila *fila, Veiculo *veiculo);

/**
 * remove o primeiro elemento da fila
 * @param fila - ponteiro para fila onde ocorrerá a remoção
 * @return - retorna o nó removido, ou nulo caso a fila esteja vazia
 */
no *remove_fila(Fila *fila);

#endif /* FILA_H */

