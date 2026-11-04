// Selection Sort: procura o menor elemento e coloca ele no começo da parte não ordenada.
// Conta quantas comparações e quantas trocas foram feitas.
// inclui as funções e estruturas comuns
#include "util.h"

// ordena o vetor v de tamanho n e devolve os contadores
Contadores selectionSort(int v[], int n) {
    // começa com comparações e trocas iguais a zero
    Contadores c;

    // a posição i vai receber o menor elemento da parte que sobra
    for (int i = 0; i < n - 1; i++) {
        // supõe que o menor elemento está na posição i
        int menor = i;

        // procura um elemento menor nas posições seguintes
        for (int j = i + 1; j < n; j++) {
            // soma 1 comparação entre v[j] e o menor atual
            c.comparacoes++;

            // se v[j] é menor que o menor atual
            if (v[j] < v[menor]) {
                // guarda a posição do novo menor
                menor = j;
            }
        }

        // só troca se o menor não estava já na posição i
        if (menor != i) {
            // coloca o menor na posição i e soma 1 nas trocas
            trocar(v[i], v[menor], c);
        }
    }

    // devolve os contadores
    return c;
}

// programa principal que testa o Selection Sort
int main() {
    // vetor de teste
    int v[] = {5, 2, 9, 1, 6, 3};
    // quantidade de elementos do vetor
    int n = 6;

    // mostra o texto da entrada
    cout << "Entrada: ";
    // mostra o vetor antes de ordenar
    imprimir(v, n);

    // ordena o vetor e guarda os contadores
    Contadores c = selectionSort(v, n);

    // mostra o texto da saída
    cout << "Saida:   ";
    // mostra o vetor depois de ordenar
    imprimir(v, n);
    // mostra o total de comparações
    cout << "Comparacoes: " << c.comparacoes << endl;
    // mostra o total de trocas
    cout << "Trocas: " << c.trocas << endl;

    // termina o programa sem erro
    return 0;
}