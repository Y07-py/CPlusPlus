#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll P, N, K, M;

ll isOK(ll P, ll A[]) {
    ll num = 0;
    for (int i = 0; i < K; ++i) {
        ll total = 0;
        while (total + A[i] <= P) {
            total += A[i];
            num++;
            if (num == N) return num;
        }
    }
    return num;
}

ll binary_search(ll A[]) {
    ll left = -1;
    ll right = 10000000000;
    ll mid;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (isOK(mid, A) >= N) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    cin >> N >> K >> M;

    return 0;
}