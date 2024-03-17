#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main() {
    int N, X; cin >> N >> X;
    ll ans = 2e18+7;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    ll s = 0;
    ll l = 1e18;
    for (int i = 0; i < N; i++) {
        s += A[i]+B[i];
        l = min<ll>(l, B[i]);
        if (X < i-1) continue;
        ans = min(ans, s + l*(X-i-1));
    }
    cout << ans << endl;
    return 0;
}