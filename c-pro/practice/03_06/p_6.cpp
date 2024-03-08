#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll ans = 0;
    for (ll a = 1; a*a*a < N+1; a++) {
        for (ll b = a; a*b*b < N+1; b++) {
            ll c = N/(a*b);
            ans += c - b + 1;
        }
    }

    cout << ans << endl;
    return 0;
}