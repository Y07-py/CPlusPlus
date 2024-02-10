#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    ll base = min(A + B, C * 2);
    ll base_ind = min(X, Y);
    ll ans = base_ind * base;
    ll amari;
    bool flag = true;
    if (X < Y) {
        amari = Y - X;
    } else {
        amari = X - Y;
        flag = false;
    }
    if (flag) {
        ll a = min(B, 2 * C);
        ans += a * amari;
    } else {
        ll a = min(A, 2 * C);
        ans += a * amari;
    }
    cout << ans << endl;
    return 0;
}