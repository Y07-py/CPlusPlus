#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500000

int A[MAX], n;

int partition(int p, int r) {
    int x, i, j, t;
    x = A[r];
    i = p - 1;
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


int main() {
    return 0;
}