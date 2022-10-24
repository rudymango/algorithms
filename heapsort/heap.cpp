#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include "../arrayfunctions.cpp"

int parent(int i) {
    return floor(i/2);
}

int left(int i) {
    return ((2*i)+1);
}

int right(int i){
    return ((2*i)+2);
}

void MaxHeapify(int A[], int n, int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if ( l <= (n-1) && A[l] > A[i] ) { largest = l; }
    if ( r <= (n-1) && A[r] > A[largest] ) { largest = r; }

    if ( largest != i ) {
        std::swap(A[i], A[largest]);
        MaxHeapify(A, n, largest);
    }
}


void BuildMaxHeap(int A[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) {
        MaxHeapify(A, n, i);
    }
}

void Heapsort(int A[], int n) {
    BuildMaxHeap(A, n);

    for (int i = n-1; i >= 0; i--) {
        std::swap(A[0], A[i]);
        MaxHeapify(A, i, 0);
    }
}
        
int main() {
    int array[50];
    int n = 50;

    import(array, 50);
    
    std::cout << "init:\t"; print(array,n);
    Heapsort(array, n);
    std::cout << "sort:\t"; print(array, n);

    return 0;
}