#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500000
#define SENTINEL 2000000000

ll L[MAX/2+2];
ll R[MAX/2+2];
ll cnt;

void Merge(ll A[], ll n, ll left, ll mid, ll right) {
    ll n1 = mid - left;
    ll n2 = right - mid;
    for (int i = 0; i < n1; ++i) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid+i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    ll i = 0;
    ll j = 0;
    for (int k = left; k < right; ++k) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(ll A[], ll n, ll left, ll right) {
    if (left+1 < right) {
        ll mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        Merge(A, n, left, mid, right);
    }
}

int main() {
    return 0;
}