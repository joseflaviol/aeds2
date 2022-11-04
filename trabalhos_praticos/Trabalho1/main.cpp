/*
 * * * * * * * * * * * * * * * * * * * * * * *
 *                                           *
 *   UNIFAL-MG - BCC - AEDS 2 - Trabalho 1   *
 *   José Flávio Lopes                       *
 *   2019.1.08.045                           *
 *                                           *  
 * * * * * * * * * * * * * * * * * * * * * * *
 */


#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    string            modelo;
    string             marca;
    string              tipo;
    int                  ano;
    int                   km;
    float  potencia_do_motor; 
    string       combustivel;
    string            cambio;
    string           direcao;
    string               cor;
    int               portas;
    string             placa;
    float              valor;
} Veiculo;

// funcoes de busca
int busca_indice(Veiculo *bd[], int tam, string placa);
Veiculo *busca(Veiculo *bd[], string placa);

// funcoes de exibicao
void exibe_bd(Veiculo *bd[], int tam, int limite);
void exibe_veiculo(Veiculo *veiculo);

// outras funcoes
int menu();
int carrega_bd(Veiculo *bd[], string arq); // retorna a quantidade de veiculos carregados no bd
void salva_bd(Veiculo *bd[], int tam, string arq);
int insere(Veiculo *bd[], int tam, Veiculo *veiculo); // retorna a posicao na qual o veiculo foi inserido, -1 caso a lista esteja cheia
Veiculo *deleta(Veiculo *bd[], int *tam, int idx);
void ordena_bd(Veiculo *bd[], Veiculo *bd_ordenado[], int tam);
void ordena_bd_por_valor(Veiculo *bd[], Veiculo *bd_valores_proximos[], int tam, float valor);
void remove_em_bd_ordenado(Veiculo *bd_ordenado[], int tam, string placa);
void insere_em_bd_ordenado(Veiculo *bd_ordenado[], int tam, Veiculo *v);
Veiculo *le_veiculo();
float modulo(float n);
int minimo(int a, int b);

int main(int argc, char** argv) {
    
    Veiculo *bd[50], *bd_ordenado[50], *bd_valores_proximos[10];
    int op = 0;
    int qtd_veiculos;
    
    qtd_veiculos = carrega_bd(bd, "BD_veiculos_2.txt");
    ordena_bd(bd, bd_ordenado, qtd_veiculos);
   
    while (op != 5) {
        op = menu();
        
        if (op == 1) {
            Veiculo *v = le_veiculo();
            
            int in = insere(bd, qtd_veiculos, v);
    
            if (in != -1) {
                cout << " - Veiculo inserido com sucesso" << endl;
                insere_em_bd_ordenado(bd_ordenado, qtd_veiculos, v);
                qtd_veiculos++;
            } else {
                cout << " - Nao foi possivel incluir o veiculo" << endl;
            }
            
        } else if (op == 2) {
            string placa;
            
            cout << " - Informe o valor da placa: ";
            cin >> placa;
            
            int idx = busca_indice(bd, qtd_veiculos, placa);
            
            if (idx != -1) {
                exibe_veiculo(bd[idx]);
                
                cout << " - Deseja remover?" << endl;
                cout << "\t1 - SIM" << endl;
                cout << "\t2 - NAO" << endl;
                cout << " - Sua escolha: " << endl;
                cin >> op;
                
                if (op == 1) {
                    Veiculo *v = deleta(bd, &qtd_veiculos, idx);
                    remove_em_bd_ordenado(bd_ordenado, qtd_veiculos, v->placa);
                    delete v;
                    cout << " - Veiculo excluido com sucesso" << endl;
                }
                        
            } else {
                cout << " - Veiculo de placa " << placa << " nao econtrado" << endl;
            }
        } else if (op == 3) {
            float valor;
            
            cout << " - Informe o valor: ";
            cin >> valor;
            
            ordena_bd_por_valor(bd, bd_valores_proximos, qtd_veiculos, valor);
            
            exibe_bd(bd_valores_proximos, 10, minimo(qtd_veiculos, 10));
        } else if (op == 4) {
            exibe_bd(bd_ordenado, qtd_veiculos, qtd_veiculos);
        } else if (op == 5) {
            salva_bd(bd, qtd_veiculos, "BD_veiculos_2.txt");
            cout << "Dados salvos no arquivo." <<  endl;
            cout << "Ate maid =D" << endl;
            break;
        } else {
            cout << " - Opcao invalida" << endl;
        }
    }
    
    return 0;
}

int menu() {
    int op;
    cout << " - Menu de Opcoes" << endl;
    cout << "\t1 - Incluir veiculo" << endl;
    cout << "\t2 - Busca por placa" << endl;
    cout << "\t3 - Busca por valor" << endl;
    cout << "\t4 - Ordenacao" << endl;
    cout << "\t5 - Sair" << endl;
    cout << " - Sua escolha: ";
    cin >> op;
    
    return op;
}

int carrega_bd(Veiculo *bd[], string arq) {
    int i = 0;
    ifstream myfile (arq);
    
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            bd[i] = new Veiculo;
             
            myfile >> bd[i]->modelo;
            myfile >> bd[i]->marca;
            myfile >> bd[i]->tipo;
            myfile >> bd[i]->ano;
            myfile >> bd[i]->km;
            myfile >> bd[i]->potencia_do_motor;
            myfile >> bd[i]->combustivel;
            myfile >> bd[i]->cambio;
            myfile >> bd[i]->direcao;
            myfile >> bd[i]->cor;
            myfile >> bd[i]->portas;
            myfile >> bd[i]->placa;
            myfile >> bd[i]->valor;
            
            i++;
        }
        
        myfile.close();
        
        for (int j = i; j < 50; j++) {
            bd[j] = NULL;
        }
    } else {
        cout << "Arquivo nao encontrado" << endl;
        exit(0);
    }
    
    return i;
}

void salva_bd(Veiculo *bd[], int tam, string arq) {
    ofstream myfile (arq);
    int i;
    
    for (i = 0; i < tam; i++) {
        myfile << bd[i]->modelo << " " << bd[i]->marca << " " << bd[i]->tipo << " " << bd[i]->ano << " " << bd[i]->km << " " << bd[i]->potencia_do_motor << " " << bd[i]->combustivel << " " << bd[i]->cambio << " " << bd[i]->direcao << " " << bd[i]->cor << " " << bd[i]->portas << " " << bd[i]->placa << " " << bd[i]->valor;            
        if (i + 1 != tam) {
            myfile << endl;
        }
    }
    
    myfile.close();
}

void exibe_bd(Veiculo *bd[], int tam, int limite) {
    int i;
    
    if (limite > tam) limite = tam;
    
    if (tam == 0) {
        cout << " - BD vazio" << endl;
    }
    
    for (i = 0; i < limite; i++) {
        exibe_veiculo(bd[i]);
    }
}

void exibe_veiculo(Veiculo *veiculo) {
    cout << " - " << veiculo->marca << " " << veiculo->modelo << " " << veiculo->placa << " " << veiculo->valor << endl;
}

int insere(Veiculo *bd[], int tam, Veiculo *veiculo) {
    int retorno = -1;
    
    if (tam < 50) {
        bd[tam] = veiculo;
        tam = tam + 1;
        retorno = tam - 1;
    }
    
    return retorno;
}

Veiculo *deleta(Veiculo *bd[], int *tam, int idx) {    
    //delete bd[idx];
    Veiculo *v = bd[idx];    
    
    bd[idx] = bd[*tam - 1];
    bd[*tam - 1] = NULL;
        
    *tam -= 1;
    
    return v;
}

int busca_indice(Veiculo *bd[], int tam, string placa) {    
    int idx = -1;
    int i;
    
    for (i = 0; i < tam; i++) {
        if (bd[i]->placa == placa) {
            idx = i;
            break;
        }
    }
    
    return idx;
}

Veiculo *busca(Veiculo *bd[], string placa) {
    Veiculo *veiculo = NULL;
    
    for (Veiculo **v = bd; *v != NULL; v++) {
        if ((*v)->placa == placa) {
            veiculo = *v;
            break;
        }
    }
    
    return veiculo;
}

void ordena_bd(Veiculo *bd[], Veiculo *bd_ordenado[], int tam) {
    int i, j;
    Veiculo *chave;
    
    for (i = 0; i < tam; i++) {
        bd_ordenado[i] = bd[i];
    }
    
    for (i = 1; i < tam; i++) {
        chave = bd_ordenado[i];
        j = i - 1;
        
        while (j > -1 && chave->placa < bd_ordenado[j]->placa) {
            bd_ordenado[j + 1] = bd_ordenado[j];
            j = j - 1;
        }
        
        bd_ordenado[j + 1] = chave;
    }
}

void ordena_bd_por_valor(Veiculo *bd[], Veiculo *bd_valores_proximos[], int tam, float valor) {
    
    int i, j;
    Veiculo *chave;
    
    if (tam > 0) {
        bd_valores_proximos[0] = bd[0];
    }
    
    for (i = 1; i < tam; i++) {
        chave = bd[i];
        j = i - 1 > 9 ? 9 : i - 1;
        
        while (j > -1 && modulo(valor - chave->valor) < modulo(valor - bd_valores_proximos[j]->valor)) {
            if (j + 1 != 10) {
                bd_valores_proximos[j + 1] = bd_valores_proximos[j];
            }
            j = j - 1;
        }
        if (j + 1 < 10) {
            bd_valores_proximos[j + 1] = chave;
        }
    }
    
}

void remove_em_bd_ordenado(Veiculo *bd_ordenado[], int tam, string placa) {
    int i, j;
    
    for (i = 0; i < tam + 1; i++) {
        if (bd_ordenado[i]->placa == placa) {
            break;
        }
    }
    
    for (j = i; j < tam; j++) {
        bd_ordenado[j] = bd_ordenado[j + 1];
    }
}

void insere_em_bd_ordenado(Veiculo *bd_ordenado[], int tam, Veiculo *v) {
    int i, j;
    
    for (i = 0; i < tam; i++) {
        if (v->placa < bd_ordenado[i]->placa) {
            break;
        }
    }
    
    for (j = tam; j > i; j--) {
        bd_ordenado[j] = bd_ordenado[j - 1];
    }
    
    bd_ordenado[i] = v;
}

Veiculo *le_veiculo() {
    Veiculo *v = new Veiculo;
    
    cout << " - Informe os dados do veiculo: " << endl;
    
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

float modulo(float n) {
    if (n < 0) return -n;
    return n;
}

int minimo(int a, int b) {
    if (a < b) {
        return a;
    }
    
    return b;
}