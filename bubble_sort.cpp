// Bubble Sort: compara vizinhos e leva o maior elemento para o fim a cada rodada.
// Conta quantas comparações e quantas trocas foram feitas.
// inclui as funções e estruturas comuns
#include "util.h"

// ordena o vetor v de tamanho n e devolve os contadores
Contadores bubbleSort(int v[], int n) {
    // começa com comparações e trocas iguais a zero
    Contadores c;

    // cada rodada i deixa mais um elemento grande no lugar certo
    for (int i = 0; i < n - 1; i++) {
        // anota se esta rodada fez alguma troca
        bool houveTroca = false;

        // percorre os pares de vizinhos que ainda não estão ordenados
        for (int j = 0; j < n - 1 - i; j++) {
            // soma 1 comparação entre v[j] e v[j + 1]
            c.comparacoes++;

            // se o da esquerda é maior, o par está fora de ordem
            if (v[j] > v[j + 1]) {
                // troca os dois de lugar e soma 1 nas trocas
                trocar(v[j], v[j + 1], c);
                // anota que houve troca nesta rodada
                houveTroca = true;
            }
        }

        // se não houve troca, o vetor já está ordenado e pode parar
        if (!houveTroca) break;
    }

    // devolve os contadores
    return c;
}

// programa principal que testa o Bubble Sort
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
    Contadores c = bubbleSort(v, n);

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