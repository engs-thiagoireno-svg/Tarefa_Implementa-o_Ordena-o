// Quick Sort: escolhe um pivô aqui, o último elemento, separa os menores ou iguais
// à esquerda e os maiores à direita partição de Lomuto e repete nos dois lados.
// Conta quantas comparações e quantas trocas foram feitas.
// Trocas de um elemento com ele mesmo mesma posição não são contadas.
#include "util.h"

// Reorganiza v[baixo..alto] em torno do pivô e devolve a posição final dele
int particionar(int v[], int baixo, int alto, Contadores &c) {
    // o pivô é o último elemento do trecho
    int pivo = v[alto];

    // i marca o fim da região dos elementos menores ou iguais ao pivô
    int i = baixo - 1;

    // percorre todos os elementos do trecho, menos o pivô
    for (int j = baixo; j < alto; j++) {
        // cada comparação entre um elemento e o pivô soma 1
        c.comparacoes++;

        // se v[j] é menor ou igual ao pivô, ele entra na região dos menores
        if (v[j] <= pivo) {
            // a região dos menores cresce uma posição
            i++;

            // troca só se as posições forem diferentes a função trocar soma 1 nas trocas
            if (i != j) {
                trocar(v[i], v[j], c);
            }
        }
    }

    // coloca o pivô entre a região dos menores e a dos maiores se já não estiver lá
    if (i + 1 != alto) {
        trocar(v[i + 1], v[alto], c);
    }

    // devolve a posição final do pivô
    return i + 1;
}

// Ordena o trecho v[baixo..alto]
void ordenar(int v[], int baixo, int alto, Contadores &c) {
    // só trabalha se o trecho tiver 2 ou mais elementos
    if (baixo < alto) {
        // coloca o pivô na posição final e recebe essa posição
        int posPivo = particionar(v, baixo, alto, c);

        // ordena os elementos à esquerda do pivô
        ordenar(v, baixo, posPivo - 1, c);

        // ordena os elementos à direita do pivô
        ordenar(v, posPivo + 1, alto, c);
    }
}

Contadores quickSort(int v[], int n) {
    // comparações e trocas começam em 0
    Contadores c;

    // ordena o vetor inteiro, da posição 0 até a última
    ordenar(v, 0, n - 1, c);

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
    Contadores c = quickSort(v, n);

    // mostra o vetor ordenado e os contadores
    cout << "Saida:   ";
    imprimir(v, n);
    cout << "Comparacoes: " << c.comparacoes << endl;
    cout << "Trocas: " << c.trocas << endl;

    return 0;
}