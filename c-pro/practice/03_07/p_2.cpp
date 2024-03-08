#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A, B; cin >> N >> A >> B;
    ll P, Q, R, S; cin >> P >> Q >> R >> S;

    for (ll i = P; i < Q+1; i++) {
        for (ll j = R; j < S+1; j++) {
            ll ki = i - A;
            ll kl = j - B;
            if (ki == kl) {
                if (max(1-A, 1-B) <= ki && ki <= (min(N-A, N-B))) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            } else if (ki == -kl) {
                if (max(1-A, B-N) <= ki && ki <=  min(N-A, B-1)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}