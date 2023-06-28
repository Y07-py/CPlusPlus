#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000

int A[MAX], n;

int partision(int p, int r) {
    int x, i, j, t;
    x = A[r];
    i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            ++i;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
}

int main() {

    return 0;
}