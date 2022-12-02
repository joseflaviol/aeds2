/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef NO_H
#define NO_H

#include "veiculo.h"

typedef struct no_ {
    Veiculo *veiculo;
    struct no_ *proximo;
} no;

#endif /* NO_H */

