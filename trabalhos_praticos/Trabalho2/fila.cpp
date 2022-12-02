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

#include "fila.h"

using namespace std;

/**
 * inicia uma fila vazia
 * @return - ponteiro para fila inciada
 */
Fila *inicia_fila() {
    Fila *f = new Fila;
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}

/**
 * cria um novo nó que aponta para o veículo, e insere o nó na fila
 * @param fila - ponteiro para a fila onde o nó será inserido
 * @param veiculo - ponteiro para o veículo que será apontado pelo novo nó
 */
void insere_fila(Fila *fila, Veiculo *veiculo) {
    no *novo_no = new no;
    
    novo_no->veiculo = veiculo;
    novo_no->proximo = NULL;
    
    if (fila->fim != NULL) {
        fila->fim->proximo = novo_no;
    } else {
        fila->inicio = novo_no;
    }
    
    fila->fim = novo_no;
}

/**
 * remove o primeiro elemento da fila
 * @param fila - ponteiro para fila onde ocorrerá a remoção
 * @return - retorna o nó removido, ou nulo caso a fila esteja vazia
 */
no *remove_fila(Fila *fila) {
    no *retorno = NULL;
    
    if (fila->inicio != NULL) {
        retorno = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
    }
    
    return retorno;
}