#include <iostream>
using namespace std;

struct Card {
    char suit;
    char value;
};

typedef Card C;

void bubbleSort(C A[], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = N-1; j >= i; --j) {
            if (A[j].value < A[j-1].value) {
                C t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
            }
        }
    }
}

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; ++i) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int N) {

}