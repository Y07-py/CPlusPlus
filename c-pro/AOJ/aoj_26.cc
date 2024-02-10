#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500000

int A[MAX];

int partision(int p, int r) {
    int x, i, j, t;
    x = A[r];
    i = p-1;
    for (j = p; j < r; j++) {
        if (x >= A[j]) {
            t = A[j];
            A[j] = A[i];
            A[i] = t;
            i++;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i + 1;
}

int quickSort(int A[], int n, int p, int r) {
    int q;
    if ( p < r) {
        q  = partision(p, r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q+1, r);
    }
}

int main() {
    return 0;
}