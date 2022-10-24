#include <iostream>
#include <fstream>

void import(int A[], int n) {
    std::ifstream myfile; myfile.open("randomlist.txt");
    int parseint;

    if (myfile.is_open()) {
        int i = 0;
        while(myfile.good() && i < n) {
            myfile >> parseint;
            A[i] = parseint;
            i++;
        }
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