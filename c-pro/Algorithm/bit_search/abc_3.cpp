#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int R, C; cin >> R >> C;
    vector<vector<int> > Senbeis(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Senbeis[i][j];
        }
    }

    ll ans = 0;
    for (ll bit = 0; bit < (1 << R); bit++) {
        vector<int> memo(C, 0);
        ll tmp = 0;
        vector<vector<int> > S = Senbeis;
        for (ll i = 0; i < R; i++) {
            if (bit & (1 << i)) {
                for (ll j = 0; j < C; j++) {
                    S[i][j] = 1 - S[i][j];
                }
            }  
        }
        for (ll i = 0; i < C; i++) {
            for (ll j = 0; j < R; j++) {
                if (S[j][i]) memo[i]++;
            }
            tmp += max(memo[i], R - memo[i]);
        }

        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}