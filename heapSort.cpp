#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i)
{
    int largest = i; // ja armazena o maior valor como a raiz
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // filho esquerdo maior que raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // filho direito é o maior de todos
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // maior não é a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
    	// aplica o heapify na sub-arvore
        heapify(arr, n, largest);
    }
}
 
// funcao principal heapSort
void heapSort(int arr[], int n)
{
    // monta o heap (reorganiza o vetor)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    //extrai os elementos do heap um por um
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // chama o max-heapify no reduced-heap
        heapify(arr, i, 0);
    }
}
