/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 2   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef VEICULO_H
#define VEICULO_H

using namespace std;

typedef struct {
    string            modelo;
    string             marca;
    string              tipo;
    int                       ano;
    int                        km;
    float       potencia_do_motor; 
    string       combustivel;
    string            cambio;
    string           direcao;
    string               cor;
    int                    portas;
    string             placa;
    float                   valor;
} Veiculo;


/**
 * recebe os dados de entrada para um veículo
 * @return - ponteiro para o veículo preenchido
 */
Veiculo *le_veiculo();

/**
 * exibe alguns dados do veículo
 * @param veiculo - ponteiro para o veículo a ser exibido
 */
void exibe_veiculo(Veiculo *veiculo);

#endif /* VEICULO_H */

