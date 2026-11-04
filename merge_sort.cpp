// Merge Sort: divide o vetor ao meio e depois junta as partes já ordenadas.
// Conta quantas comparações foram feitas.
// No Merge Sort ninguém troca de lugar, então cada cópia de um elemento para o vetor conta como uma troca.
// inclui as funções e estruturas comuns
#include "util.h"

// junta as duas metades ordenadas, a da esquerda e a da direita
void intercalar(int v[], int aux[], int inicio, int meio, int fim, Contadores &c) {
    // copia o trecho para o vetor auxiliar, para não perder valores ao sobrescrever v
    for (int p = inicio; p <= fim; p++) {
        // copia um elemento de v para aux
        aux[p] = v[p];
    }

    // i lê a metade da esquerda
    int i = inicio;
    // j lê a metade da direita
    int j = meio + 1;
    // k é a posição de v onde vai escrever
    int k = inicio;

    // repete enquanto as duas metades ainda têm elementos
    while (i <= meio && j <= fim) {
        // soma 1 comparação entre aux[i] e aux[j]
        c.comparacoes++;

        // se o da esquerda é menor ou igual, ele vai primeiro
        if (aux[i] <= aux[j]) {
            // copia o da esquerda para v
            v[k] = aux[i];
            // avança na metade da esquerda
            i++;
        } else {  // senão o da direita é menor
            // copia o da direita para v
            v[k] = aux[j];
            // avança na metade da direita
            j++;
        }

        // soma 1 cópia, que conta como uma troca
        c.trocas++;
        // avança a posição de escrita
        k++;
    }

    // repete enquanto sobrou elemento na metade da esquerda
    while (i <= meio) {
        // copia o elemento que sobrou para v
        v[k] = aux[i];
        // avança na metade da esquerda
        i++;
        // avança a posição de escrita
        k++;
        // soma 1 cópia, que conta como uma troca
        c.trocas++;
    }

    // repete enquanto sobrou elemento na metade da direita
    while (j <= fim) {
        // copia o elemento que sobrou para v
        v[k] = aux[j];
        // avança na metade da direita
        j++;
        // avança a posição de escrita
        k++;
        // soma 1 cópia, que conta como uma troca
        c.trocas++;
    }
}

// divide o trecho ao meio, ordena cada metade e junta as duas
void ordenar(int v[], int aux[], int inicio, int fim, Contadores &c) {
    // trecho com 0 ou 1 elemento já está ordenado, então para
    if (inicio >= fim) return;

    // calcula a posição do meio do trecho
    int meio = (inicio + fim) / 2;

    // ordena a metade da esquerda
    ordenar(v, aux, inicio, meio, c);
    // ordena a metade da direita
    ordenar(v, aux, meio + 1, fim, c);
    // junta as duas metades ordenadas
    intercalar(v, aux, inicio, meio, fim, c);
}

// ordena o vetor v de tamanho n e devolve os contadores
Contadores mergeSort(int v[], int n) {
    // começa com comparações e trocas iguais a zero
    Contadores c;

    // vetor auxiliar com espaço para até 100 elementos
    int aux[100];

    // ordena o vetor inteiro, da posição 0 até a última
    ordenar(v, aux, 0, n - 1, c);

    // devolve os contadores
    return c;
}

// programa principal que testa o Merge Sort
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
    Contadores c = mergeSort(v, n);

    // mostra o texto da saída
    cout << "Saida:   ";
    // mostra o vetor depois de ordenar
    imprimir(v, n);
    // mostra o total de comparações
    cout << "Comparacoes: " << c.comparacoes << endl;
    // mostra o total de trocas, que aqui são as cópias
    cout << "Trocas: " << c.trocas << endl;

    // termina o programa sem erro
    return 0;
}