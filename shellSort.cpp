#include <iostream>
using namespace std;

// Fun��o para realizar o Shell Sort utilizando a f�rmula de Knuth para gaps
void shellSort(int arr[], int n) {
    // Calcula o maior intervalo (gap) utilizando a f�rmula de Knuth que seja menor que n
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }
    
    // Inicializa o intervalo e o reduz progressivamente utilizando a f�rmula de Knuth
    for (; gap > 0; gap = (gap - 1) / 3) {
        // Executa a ordena��o por inser��o com os elementos a uma dist�ncia 'gap'
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Guarda o valor atual
            int j;
            // Desloca os elementos do array para frente at� encontrar a posi��o correta para 'temp'
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp; // Coloca 'temp' na posi��o correta
        }
    }
}



