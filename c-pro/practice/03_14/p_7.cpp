#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int M = 200005;
    vector<ll> D(M);
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        D[a]++;
    }
    ll ans = 0;
    for (int a = 1; a < M; a++) {
        for (int b = 1; b <= (M-1) / a; b++) {
            ll c = a*b;
            ans += D[a]*D[b]*D[c];
        }
    }
    cout << ans << endl;
    return 0;
}