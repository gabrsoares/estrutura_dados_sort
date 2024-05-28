#include <vector>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivotValue = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}




