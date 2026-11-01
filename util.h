// util.h - estruturas e funções usadas por todos os algoritmos

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using namespace std;

// Guarda os contadores de uma execução
struct Contadores {
    int comparacoes = 0;
    int trocas = 0;
};

// Troca o conteúdo de duas posições e conta a troca
inline void trocar(int &a, int &b, Contadores &c) {
    int aux = a;
    a = b;
    b = aux;
    c.trocas++;
}

// Imprime o vetor no formato a, b, c e pula uma linha
inline void imprimir(const int v[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

#endif