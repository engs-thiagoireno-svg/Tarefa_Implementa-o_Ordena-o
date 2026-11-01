// Selection Sort: a cada passada, escolhe o menor elemento do trecho não ordenado
// e o coloca na primeira posição desse trecho.
// Conta quantas comparações e quantas trocas foram feitas.

#include "util.h"

Contadores selectionSort(int v[], int n) {
    // comparações e trocas começam em 0
    Contadores c;

    // passada i: ao final dela, a posição i já guarda o elemento definitivo
    for (int i = 0; i < n - 1; i++) {
        // supõe que o menor elemento do trecho está na posição i
        int menor = i;

        // procura um elemento menor nas posições seguintes
        for (int j = i + 1; j < n; j++) {
            // cada comparação entre dois elementos soma 1
            c.comparacoes++;

            // se v[j] é menor que o menor atual, guarda a posição dele
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        // só troca se o menor não estava já na posição i
        if (menor != i) {
            // coloca o menor na posição i a função trocar também soma 1 nas trocas
            trocar(v[i], v[menor], c);
        }
    }

    // devolve o total de comparações e trocas
    return c;
}

int main() {
    // vetor de teste e quantidade de elementos
    int v[] = {5, 2, 9, 1, 6, 3};
    int n = 6;

    // mostra o vetor antes de ordenar
    cout << "Entrada: ";
    imprimir(v, n);

    // ordena o vetor e guarda os contadores
    Contadores c = selectionSort(v, n);

    // mostra o vetor ordenado e os contadores
    cout << "Saida:   ";
    imprimir(v, n);
    cout << "Comparacoes: " << c.comparacoes << endl;
    cout << "Trocas: " << c.trocas << endl;

    return 0;
}