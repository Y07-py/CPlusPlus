#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXMOD 1000000007

ll solve(ll x, ll ans) {
    if (x == 1) {
        return ans % MAXMOD;
    }
    ans = (ans * x) % MAXMOD;
    return solve(x - 1, ans);
}

int main() {
    ll N, M; cin >> N >> M;
    ll larger = max(N, M);
    if (N == M) {
        ll N_1 = solve(N, 1);
        ll M_1 = solve(M, 1);
        cout << ((N_1 * M_1) % MAXMOD * 2) % MAXMOD << endl;
        return 0;
    }
    int dif = max(N - M, M - N);
    if (dif == 1) {
        ll N_1 = solve(N, 1);
        ll M_1 = solve(M, 1);
        cout << (N_1 * M_1) % MAXMOD << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}