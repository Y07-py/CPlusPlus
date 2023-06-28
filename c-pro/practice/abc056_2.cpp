#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll W, a, b; cin >> W >> a >> b;
    if (b > a) {
        ll ans = b - (a + W);
        if (ans < 0) {
            cout << 0 << endl;
            return 0;
        }
        cout << ans << endl;
    } else {
        ll ans_2 = a - (b + W);
        if (ans_2 < 0) {
            cout << 0 << endl;
            return 0;
        }
        cout << ans_2 << endl;
    }
    return 0;
}