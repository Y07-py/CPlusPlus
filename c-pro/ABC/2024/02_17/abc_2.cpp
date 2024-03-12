#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    vector<ll> S(N-1);
    vector<ll> T(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> S[i] >> T[i];
    }
    for (int i = 0; i < N-1; i++) {
        ll count = A[i] / S[i];
        A[i] -= S[i] * count;
        A[i+1] += T[i] * count;
    }
    cout << A[N-1] << endl;
    return 0;
}