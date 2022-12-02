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

#include "veiculo.h"

using namespace std;

/**
 * recebe os dados de entrada para um veículo
 * @return - ponteiro para o veículo preenchido
 */
Veiculo *le_veiculo() {
    Veiculo *v = new Veiculo;
    
    cin >> v->modelo;
    cin >> v->marca;
    cin >> v->tipo;
    cin >> v->ano;
    cin >> v->km;
    cin >> v->potencia_do_motor;
    cin >> v->combustivel;
    cin >> v->cambio;
    cin >> v->direcao;
    cin >> v->cor;
    cin >> v->portas;
    cin >> v->placa;
    cin >> v->valor;
    
    return v;
}

/**
 * exibe alguns dados do veículo
 * @param veiculo - ponteiro para o veículo a ser exibido
 */
void exibe_veiculo(Veiculo *veiculo) {
    cout << veiculo->placa << " " << veiculo->marca << " " << veiculo->modelo << " " << veiculo->valor << endl;
}


