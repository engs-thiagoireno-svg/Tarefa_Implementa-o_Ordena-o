// Insertion Sort: mantém a parte da esquerda ordenada e encaixa cada novo elemento
// na posição certa, trocando com o vizinho maior até ele achar o lugar.
// Conta quantas comparações e quantas trocas foram feitas.
#include "util.h"

Contadores insertionSort(int v[], int n) {
    // comparações e trocas começam em 0
    Contadores c;

    // v[0..i-1] já está ordenado; agora vamos encaixar o elemento v[i]
    for (int i = 1; i < n; i++) {
        // j é a posição atual do elemento que está sendo encaixado
        int j = i;

        // continua enquanto o elemento não chegou ao início do vetor
        while (j > 0) {
            // cada comparação entre dois elementos soma 1
            c.comparacoes++;

            // se o vizinho da esquerda é maior, o elemento ainda precisa andar para a esquerda
            if (v[j - 1] > v[j]) {
                // troca com o vizinho a função trocar também soma 1 nas trocas
                trocar(v[j - 1], v[j], c);
                // o elemento agora está uma posição mais à esquerda
                j--;
            } else {
                // o vizinho é menor ou igual: o elemento já está no lugar certo
                break;
            }
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
    Contadores c = insertionSort(v, n);

    // mostra o vetor ordenado e os contadores
    cout << "Saida:   ";
    imprimir(v, n);
    cout << "Comparacoes: " << c.comparacoes << endl;
    cout << "Trocas: " << c.trocas << endl;

    return 0;
}