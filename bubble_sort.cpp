// Bubble Sort: compara vizinhos e empurra o maior elemento para o fim a cada passada.
// Conta quantas comparações e quantas trocas foram feitas.

#include "util.h"

Contadores bubbleSort(int v[], int n) {
    // comparações e trocas começam em 0
    Contadores c;

    // passada i: ao final dela, os i + 1 maiores elementos já estão no lugar certo
    for (int i = 0; i < n - 1; i++) {
        // se nenhuma troca acontecer nesta passada, o vetor já está ordenado
        bool houveTroca = false;

        // j percorre os pares (v[j], v[j + 1]); os últimos i elementos já estão ordenados e ficam de fora
        for (int j = 0; j < n - 1 - i; j++) {
            // cada comparação entre dois elementos soma 1
            c.comparacoes++;

            // se o da esquerda é maior que o da direita, o par está fora de ordem
            if (v[j] > v[j + 1]) {
                // troca os dois de lugar (a função trocar também soma 1 nas trocas)
                trocar(v[j], v[j + 1], c);
                // anota que houve troca nesta passada
                houveTroca = true;
            }
        }

        // passada sem trocas significa vetor ordenado: não precisa continuar
        if (!houveTroca) break;
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
    Contadores c = bubbleSort(v, n);

    // mostra o vetor ordenado e os contadores
    cout << "Saida:   ";
    imprimir(v, n);
    cout << "Comparacoes: " << c.comparacoes << endl;
    cout << "Trocas: " << c.trocas << endl;

    return 0;
}