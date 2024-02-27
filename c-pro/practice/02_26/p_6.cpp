#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    ll K; cin >> K;
    vector<ll> A(N);
    vector<ll> T(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        T[i] = A[i];
    }
    sort(A.begin(), A.end());
    map<ll, ll> cnt;
    for (int i = 0; i < N; i++) {
        cnt[A[i]] = K / N;
    }
    K = K % N;
    for (int i = 0; i < K; i++) {
        cnt[A[i]] += 1;
    }
    for (int i = 0; i < N; i++) {
        cout << cnt[T[i]] << endl;
    }
    return 0;
}