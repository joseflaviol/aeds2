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
#include <fstream>

#include "no.h"
#include "veiculo.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"

using namespace std;

int menu();
void carrega_veiculos(Lista *veiculos, Lista *veiculos_ordenados, string arq_nome);
void salva_veiculos(Lista *veiculos, string arq_nome);

int main() {

    int op = 0;
    string placa;
    Lista *veiculos = inicia_lista();
    Lista *veiculos_ordenados = inicia_lista();
    
    carrega_veiculos(veiculos, veiculos_ordenados, "BD_veiculos_2.txt");
    
    cout << veiculos->tamanho << " veiculos carregados." << endl;
    
    while (op != 6) {
        op = menu();
        
        if (op == 1) {
            Veiculo *v = le_veiculo();
            
            if (insere(veiculos_ordenados, v, true) == 1) {
                insere(veiculos, v, false);
                cout << "Veiculo inserido com sucesso." << endl;
            } else {
                cout << "Falha ao inserir veiculo." << endl;
            }
        } else if (op == 2) {
            cout << "placa: ";
            cin >> placa;
            
            no *ant, *pont;
            
            busca_ordenada(veiculos_ordenados, &ant, &pont, placa);
            
            if (pont != NULL) {
                cout << "Veiculo encontrado" << endl;
                exibe_veiculo(pont->veiculo);
                
                cout << "Deseja remove-lo?" << endl;
                cout << "\t1 - SIM" << endl;
                cout << "\t2 - NAO" << endl;
                cout << "sua escolha: ";
                
                cin >> op;
                
                if (op == 1) {
                    deleta(veiculos_ordenados, ant, pont);
                    delete(pont);
                    busca(veiculos, &ant, &pont, placa);
                    deleta(veiculos, ant, pont);
                    cout << "Veiculo " << pont->veiculo->placa << " excluido." << endl;
                    //delete(pont->veiculo);
                    delete(pont);
                }
            } else {
                cout << "Veiculo nao encontrado" << endl;
            }
        } else if (op == 3) {
            exibe(veiculos_ordenados);
        } else if (op == 4) {
            
            Pilha *p = inicia_pilha();
            no *q = veiculos->inicio->proximo;
            no *n;
            
            while (q != NULL) {
                if (q->veiculo->direcao == "Hidráulica") {
                    insere_pilha(p, q->veiculo);
                } else if (q->veiculo->direcao == "Elétrica") {
                    delete(remove_pilha(p));
                }
                
                q = q->proximo;
            }
            
            while (p->topo != NULL) {
                n = remove_pilha(p);
                cout << "Removido da pilha: " << n->veiculo->placa << endl;
                delete(n);
            }
            
            delete(p);
        } else if (op == 5) {
            
            Fila *f = inicia_fila();
            no *q = veiculos->inicio->proximo;
            no *n;
            
            while (q != NULL) {
                if (q->veiculo->cambio == "Automático") {
                    insere_fila(f, q->veiculo);
                } else if (q->veiculo->cambio == "Manual") {
                    delete(remove_fila(f));
                }
                
                q = q->proximo;
            }
            
            while (f->fim != NULL) {
                n = remove_fila(f);
                
                cout << "Removido da fila: " << n->veiculo->placa << endl;
                
                delete(n);
            }
            
            delete(f);
            
        } else if (op == 6) {
            cout << "Ate mais! :D" << endl;
        }
    }
    
    salva_veiculos(veiculos, "BD_veiculos_2.txt");
    
    encerra_lista(veiculos);
    encerra_lista(veiculos_ordenados);
    
    return 0;
    
}

int menu() {
    int op;
    
    cout << " ---------- Menu ----------" << endl;
    cout << "|\t1 - Inserir        |" << endl;
    cout << "|\t2 - Buscar         |" << endl;
    cout << "|\t3 - Exibir         |" << endl;
    cout << "|\t4 - Pilha          |" << endl;
    cout << "|\t5 - Fila           |" << endl;
    cout << "|\t6 - Sair           |" << endl;
    cout << " --------------------------" << endl;
    cout << "sua escolha: ";
    
    cin >> op;

    return op;
}

void carrega_veiculos(Lista *veiculos, Lista *veiculos_ordenados, string arq_nome) {
    ifstream bd (arq_nome);
    
    if (bd.is_open()) {
        
        while (!bd.eof()) {
            Veiculo *v = new Veiculo;
            
            bd >> v->modelo;
            bd >> v->marca;
            bd >> v->tipo;
            bd >> v->ano;
            bd >> v->km;
            bd >> v->potencia_do_motor;
            bd >> v->combustivel;
            bd >> v->cambio;
            bd >> v->direcao;
            bd >> v->cor;
            bd >> v->portas;
            bd >> v->placa;
            bd >> v->valor;
            
            insere(veiculos, v, false);
            insere(veiculos_ordenados, v, true);
        }
        
        bd.close();
    }
}

void salva_veiculos(Lista *veiculos, string arq_nome) {
    ofstream bd (arq_nome);
    
    no *n = veiculos->inicio->proximo;
    
    while (n != NULL) {
        bd << n->veiculo->modelo << " " << n->veiculo->marca << " " << n->veiculo->tipo << " " << n->veiculo->ano << " " << n->veiculo->km << " " << n->veiculo->potencia_do_motor << " " << n->veiculo->combustivel << " " << n->veiculo->cambio << " " << n->veiculo->direcao << " " << n->veiculo->cor << " " << n->veiculo->portas << " " << n->veiculo->placa << " " << n->veiculo->valor; 
    
        n = n->proximo;
        
        if (n != NULL) {
            bd << endl;
        }
    }
    
    bd.close();
}
