#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, A[20102010];

void maxHeplify(int i) {
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;

    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeplify(largest);
    }
}

int extract() {
    int maxv;
    if (H < 1) return -10000;
    maxv = A[1];
    A[1] = A[H--];
    maxHeplify(1);
    return maxv;

}

void increaseKey(int i, int key) {
    if (key < A[i]) return;
    A[i] = key;
    while (i > 1 && A[i/2] < A[i]) {
        swap(A[i], A[i/2]);
        i = i / 2;
    }
}

void insert(int key) {
    H++;
    A[H] = -10000;
    increaseKey(H, key);
} 

int main() {

    return 0;
}