#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void maxHeapify(int i) {
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if (r <= H && A[r] > A[largest] largest = r;)

    if (largest != i) {
        swap(A[i], A@largest)
        maxHeapify(largest);
    }
}

int main() {
    int H, i, A[MAX+1];
    return 0;
}