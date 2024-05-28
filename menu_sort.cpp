#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "heapsort.cpp"
#include "quickSort.cpp"
#include "shellSort.cpp"

using namespace std;

string txt_arquivo = "list.txt";

int contarLinhas(string txt);
void printArray(int arr[], int n);

int main () {
	double time1, timedif;
	int numeroLinhas = contarLinhas(txt_arquivo);
	//cada sort vai receber uma lista igual para tratá-la
	int listaShell[numeroLinhas];
	int listaQuick[numeroLinhas];
	int listaHeap[numeroLinhas];
	
	ifstream arquivo(txt_arquivo.c_str()); //armazenamento do txt
	string linha;
	int i = 0;
	
	while(getline (arquivo, linha)) { //armazena os valores da lista no vetor listaNumeros[]
		listaShell[i] = atoi(linha.c_str());
		listaQuick[i] = atoi(linha.c_str());
		listaHeap[i] = atoi(linha.c_str());
		
		i++;
	}
	int n = sizeof(listaShell) / sizeof(listaShell[0]); // aqui tanto faz a lista, todas possuem o mesmo tamanho

	/* Codigo abaixo comentado para reduzir o tamanho do console de resultado, mas basicamente exibe a lista importada e desorganizada */
	
	//cout<<"Vetor desorganizado:\n";
	//for (i = 0; i < numeroLinhas; i++){
	//	cout<<listaNumeros[i]<<", ";
	//}
	
	
	/* ------------------ shellSort ------------------ */
	
	// chama o relogio para iniciar a contagem do tempo de execucao
	time1 = (double)clock();
	time1 = time1/CLOCKS_PER_SEC;	

    shellSort(listaShell, n);
    cout << "\nVetor organizado por Shell Sort \n";
    printArray(listaShell, n); // comentar essa linha caso nao queira exibir a lista organizada no console

	// chama relogio novamente para finalizar a contagem do tempo de execucao
	timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
	cout<<"\nTempo de execucao do Shell Sort: "<<timedif<<"s"<<endl;
	
	
	/* ------------------ quickSort ------------------ */
	
	// chama o relógio para iniciar a contagem do tempo de execução
    time1 = (double)clock();
    time1 = time1/CLOCKS_PER_SEC;

    // chama a função quicksort para ordenar o vetor listaNumeros[]
   	quickSort(listaQuick, 0, numeroLinhas - 1);
   	cout << "\nVetor organizado por quickSort \n";
	printArray(listaQuick, n); // comentar essa linha caso nao queira exibir a lista organizada no console
   
    // para parar o relógio e calcular o tempo de execução
    timedif = ((double)clock() - time1) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao do Quick Sort: " << timedif << " segundos" << endl;
    
	
	/* ------------------ heapSort ------------------ */
	
	//chama o relogio para iniciar a contagem do tempo de execucao
	time1 = (double)clock();
	time1 = time1/CLOCKS_PER_SEC;	
		
    for(int i=n/2 -1;i>=0;i--){
       heapify(listaHeap,n,i);
   	}
    heapSort(listaHeap, n);
    cout << "\nVetor organizado por heapSort \n";
    printArray(listaHeap, n); // comentar essa linha caso nao queira exibir a lista organizada no console

	//chama relogio novamente para finalizar a contagem do tempo de exec
	timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
	cout<<"\nTempo de execucao do Heap Sort: "<<timedif<<"s"<<endl;
	
	return 0;
}

int contarLinhas(string txt){ //função para identificar numero de linhas
	int linhas = 0;
	ifstream arquivo(txt.c_str());
	string linha;
	
	while(getline (arquivo, linha)) { 
		linhas++;
	}
	arquivo.close();
	return linhas;
}

void printArray(int arr[], int n) { //exibe a lista
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

