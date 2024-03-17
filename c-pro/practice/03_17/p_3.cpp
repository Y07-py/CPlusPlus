#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        int k = upper_bound(A.begin(), A.end(), x) - A.begin();
        ll ans = (ll)k*x - S[k];
        ans += (S[N] - S[k]) - (ll)(N-k)*x;
        cout << ans << endl;
    }
    return 0;
}