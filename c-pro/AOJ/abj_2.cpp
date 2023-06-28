#include <iostream>
#include <stdio.h>

void trace(int A[], int N) {
    for (int i = 0; i < N; ++i) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N) {
    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j =  i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = N-1; j >= i+1; j--) {
            if (A[j] < A[j-1]) {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = true;
                sw++;
            }
        }
    }
}

int selectionSort(int A[], int N) {
    for (int i = 0; i < N-1; ++i) {
        int minj = A[i];
        for (int j = i+1; j < N; ++j) {
            if (A[j] < minj) {
                int t = A[j];
                minj = A[j];
                A[j] = A[i];
                A[i] = t;
            }
        }
    }
}