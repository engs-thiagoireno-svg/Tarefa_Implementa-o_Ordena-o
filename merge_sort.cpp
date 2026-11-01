// Merge Sort: divide o vetor ao meio até sobrar 1 elemento em cada parte
// e depois intercala (junta) as partes já ordenadas.
// Conta quantas comparações foram feitas.
// No Merge Sort não existe troca de posições: o que acontece são cópias de elementos
// para o vetor durante a intercalação. Cada cópia conta como uma troca (movimentação).

#include "util.h"

// Junta v[inicio..meio] e v[meio+1..fim], que já estão ordenados cada um
void intercalar(int v[], int aux[], int inicio, int meio, int fim, Contadores &c) {
    // copia o trecho para o vetor auxiliar, para poder sobrescrever v sem perder valores
    for (int p = inicio; p <= fim; p++) {
        aux[p] = v[p];
    }

    // i lê a metade esquerda, j lê a metade direita e k escreve em v
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    // enquanto as duas metades ainda têm elementos para comparar
    while (i <= meio && j <= fim) {
        // cada comparação entre dois elementos soma 1
        c.comparacoes++;

        // se o da esquerda é menor ou igual, ele vai primeiro
        if (aux[i] <= aux[j]) {
            // copia o da esquerda para v e avança na esquerda
            v[k] = aux[i];
            i++;
        } else {
            // senão copia o da direita para v e avança na direita
            v[k] = aux[j];
            j++;
        }

        // conta a cópia como uma troca (movimentação) e avança a posição de escrita
        c.trocas++;
        k++;
    }

    // se sobrou algo na esquerda, copia o restante
    while (i <= meio) {
        v[k] = aux[i];
        i++;
        k++;
        c.trocas++;
    }

    // se sobrou algo na direita, copia o restante
    while (j <= fim) {
        v[k] = aux[j];
        j++;
        k++;
        c.trocas++;
    }
}

// Ordena o trecho v[inicio..fim] dividindo, ordenando cada metade e intercalando
void ordenar(int v[], int aux[], int inicio, int fim, Contadores &c) {
    // caso base: trecho com 0 ou 1 elemento já está ordenado
    if (inicio >= fim) return;

    // posição do meio do trecho
    int meio = (inicio + fim) / 2;

    // ordena a metade esquerda
    ordenar(v, aux, inicio, meio, c);

    // ordena a metade direita
    ordenar(v, aux, meio + 1, fim, c);

    // junta as duas metades já ordenadas
    intercalar(v, aux, inicio, meio, fim, c);
}

Contadores mergeSort(int v[], int n) {
    // comparações e trocas começam em 0
    Contadores c;

    // vetor auxiliar usado na intercalação (suporta até 100 elementos)
    int aux[100];

    // ordena o vetor inteiro, da posição 0 até a última
    ordenar(v, aux, 0, n - 1, c);

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
    Contadores c = mergeSort(v, n);

    // mostra o vetor ordenado e os contadores
    cout << "Saida:   ";
    imprimir(v, n);
    cout << "Comparacoes: " << c.comparacoes << endl;
    cout << "Trocas (movimentacoes): " << c.trocas << endl;

    return 0;
}