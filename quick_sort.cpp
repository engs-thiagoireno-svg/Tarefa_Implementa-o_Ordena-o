// Quick Sort: escolhe um pivô, que aqui é o último elemento, e separa os menores ou iguais
// para a esquerda e os maiores para a direita. Depois repete nos dois lados.
// Conta quantas comparações e quantas trocas foram feitas.
// Trocar um elemento com ele mesmo não conta como troca.
// inclui as funções e estruturas comuns
#include "util.h"

// separa o trecho em torno do pivô e devolve a posição final dele
int particionar(int v[], int baixo, int alto, Contadores &c) {
    // o pivô é o último elemento do trecho
    int pivo = v[alto];

    // i marca o fim da região dos elementos menores ou iguais ao pivô
    int i = baixo - 1;

    // percorre todos os elementos do trecho, menos o pivô
    for (int j = baixo; j < alto; j++) {
        // soma 1 comparação entre v[j] e o pivô
        c.comparacoes++;

        // se v[j] é menor ou igual ao pivô
        if (v[j] <= pivo) {
            // a região dos menores cresce uma posição
            i++;

            // só troca se as posições forem diferentes
            if (i != j) {
                // troca os dois de lugar e soma 1 nas trocas
                trocar(v[i], v[j], c);
            }
        }
    }

    // se o pivô ainda não está na posição certa
    if (i + 1 != alto) {
        // coloca o pivô entre os menores e os maiores e soma 1 nas trocas
        trocar(v[i + 1], v[alto], c);
    }

    // devolve a posição final do pivô
    return i + 1;
}

// ordena o trecho de baixo até alto
void ordenar(int v[], int baixo, int alto, Contadores &c) {
    // só trabalha se o trecho tem 2 ou mais elementos
    if (baixo < alto) {
        // coloca o pivô no lugar certo e guarda a posição dele
        int posPivo = particionar(v, baixo, alto, c);

        // ordena os elementos à esquerda do pivô
        ordenar(v, baixo, posPivo - 1, c);
        // ordena os elementos à direita do pivô
        ordenar(v, posPivo + 1, alto, c);
    }
}

// ordena o vetor v de tamanho n e devolve os contadores
Contadores quickSort(int v[], int n) {
    // começa com comparações e trocas iguais a zero
    Contadores c;

    // ordena o vetor inteiro, da posição 0 até a última
    ordenar(v, 0, n - 1, c);

    // devolve os contadores
    return c;
}

// programa principal que testa o Quick Sort
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
    Contadores c = quickSort(v, n);

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