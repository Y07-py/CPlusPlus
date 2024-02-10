#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}

int main() {
    int N, i, j;
    int A[100];

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
    insertionSort(A, N);

    for (int k = 0; k < N; k++) {
        cout << A[k] << " ";
    }
    cout << endl;

    return 0;
}