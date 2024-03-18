#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    ll now = 0;
    ll S = 0;
    for (int i = 0; i < M; i++) now += A[i]*(i+1);
    for (int i = 0; i < M; i++) S += A[i];
    ans = now;
    for (int i = 0; i < N-M; i++) {
        ll ns = now - S + M*A[i+M];
        ll nt = S - A[i] + A[i+M];
        S = nt;
        now = ns;
        ans = max(now, ans);
    }
    cout << ans << endl;
    return 0;
}