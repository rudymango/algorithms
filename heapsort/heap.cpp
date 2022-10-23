#include <iostream>
#include <cmath>

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

void print(int A[], int n) {
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << A[i];
        if (i < n-1) {std::cout << ", ";} 
    }
    std::cout << "]" << std::endl;
}
        
int main() {
    int arr[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "init:\t"; print(arr, n);
    Heapsort(arr, n);
    std::cout << "sort:\t"; print(arr, n);

    return 0;
}