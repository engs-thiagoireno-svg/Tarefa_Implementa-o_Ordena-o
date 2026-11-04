// Insertion Sort: mantém o lado esquerdo ordenado e encaixa cada elemento novo no lugar certo.
// Conta quantas comparações e quantas trocas foram feitas.
// inclui as funções e estruturas comuns
#include "util.h"

// ordena o vetor v de tamanho n e devolve os contadores
Contadores insertionSort(int v[], int n) {
    // começa com comparações e trocas iguais a zero
    Contadores c;

    // tudo antes de i já está ordenado, agora encaixa o elemento v[i]
    for (int i = 1; i < n; i++) {
        // j é a posição atual do elemento que está sendo encaixado
        int j = i;

        // repete enquanto o elemento não chegou ao início do vetor
        while (j > 0) {
            // soma 1 comparação entre o vizinho da esquerda e o elemento
            c.comparacoes++;

            // se o vizinho da esquerda é maior, o elemento precisa andar para a esquerda
            if (v[j - 1] > v[j]) {
                // troca os dois de lugar e soma 1 nas trocas
                trocar(v[j - 1], v[j], c);
                // o elemento agora está uma posição mais à esquerda
                j--;
            } else {  // senão o vizinho é menor ou igual
                // o elemento já está no lugar certo, então para de comparar
                break;
            }
        }
    }

    // devolve os contadores
    return c;
}

// programa principal que testa o Insertion Sort
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
    Contadores c = insertionSort(v, n);

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