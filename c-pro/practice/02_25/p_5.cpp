#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, K; cin >> A >> B >> K;

    ll C[100][100];
    C[0][0] = 1;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < i+1; j++) {
            C[i+1][j] += C[i][j];
            C[i+1][j+1] += C[i][j];
        }
    }

    string ans;
    while (A+B > 0) {
        ll x = 0;
        if (A >= 1) x = C[A+B-1][A-1];
        if (K <= x) {
            ans += 'a';
            --A;
        } else {
            ans += 'b';
            --B;
            K -= x;
        }
    }
    cout << ans << endl;
    return 0;
}