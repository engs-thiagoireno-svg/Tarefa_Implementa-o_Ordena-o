// util.h guarda o que todos os algoritmos usam
// evita que este arquivo seja incluído duas vezes
#ifndef UTIL_H
// marca que este arquivo já foi incluído
#define UTIL_H

// inclui a biblioteca de entrada e saída, usada pelo cout
#include <iostream>
// permite escrever cout sem precisar escrever std:: antes
using namespace std;

// guarda os contadores de uma execução
struct Contadores {
    // quantidade de comparações feitas
    int comparacoes = 0;
    // quantidade de trocas feitas
    int trocas = 0;
};

// troca o valor de duas posições e soma 1 nas trocas
inline void trocar(int &a, int &b, Contadores &c) {
    // guarda o valor de a numa variável auxiliar
    int aux = a;
    // coloca o valor de b em a
    a = b;
    // coloca o valor guardado em b
    b = aux;
    // soma 1 no contador de trocas
    c.trocas++;
}

// imprime o vetor entre colchetes e pula uma linha
inline void imprimir(const int v[], int n) {
    // abre o colchete
    cout << "[";
    // percorre todos os elementos do vetor
    for (int i = 0; i < n; i++) {
        // imprime o elemento
        cout << v[i];
        // coloca vírgula, menos depois do último elemento
        if (i < n - 1) cout << ", ";
    }
    // fecha o colchete e pula uma linha
    cout << "]" << endl;
}

// fecha o bloco do ifndef
#endif