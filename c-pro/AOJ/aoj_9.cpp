#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50000000
#define SENTINEL 2000000000

struct Card {
    char suit;
    ll value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], ll n, ll left, ll mid, ll right) {
    ll n1 = mid - left;
    ll n2 = right - mid;
    for (ll i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (ll i = 0; i < n2; ++i) {
        R[i] = A[mid + i];
    }
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;
    ll i = 0, j = 0;
    for (ll k = left; k < right; ++k) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(struct Card A[], ll n, ll left, ll right) {
    if (left + 1 < right) {
        ll mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

ll partition(struct Card A[], ll n, ll p, ll r) {
    ll i, j;
    struct Card t, x;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i+1;
}

void quickSort(struct Card A[], ll n, ll p, ll r) {
    ll q;
    if (p < r) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q+1, r);
    }
}

for (int i = 0; i< N; ++i) {
    A[i] = A[i] + A[i-1];
}

int main() {

    return 0;
}