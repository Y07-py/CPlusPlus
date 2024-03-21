#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;

    ll ans = 1e18;
    for (int ai = 0; ai < N; ai++) {
        ll now = (ll)A*ai;
        string T = S;
        rotate(T.begin(), T.begin()+ai, T.end());
        for (int l = 0, r = N-1; l < r ; l++, r--) {
            if (T[l] != T[r]) now += B;
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}