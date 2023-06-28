#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define HUSLISTIC 10000000

int L[MAX/2+2];
int R[MAX/2+2];
int cnt;

void merge(int A[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; ++i) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid+i];
    }
    L[n1] = HUSLISTIC;
    R[n2] = HUSLISTIC;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; ++k) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right) {
    if ( left+1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    int N; cin >> N;
    int A[MAX];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    mergeSort(A, N, 0, N);
    cout << A[N-1] - A[0] << endl;
    return 0;
}