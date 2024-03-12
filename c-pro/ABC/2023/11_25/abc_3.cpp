#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF = 2e16;

int main() {
    ll D; cin >> D;
    ll ans = D;
    for (int i = 0; i <= sqrt(D) + 1; i++) {
        ll c = i*i - D;
        if (c >= 0) {
            ans = min(ans, c);
        } else {
            ll y = sqrt(-c);
            ans = min(ans, abs(-D + (i*i + y*y)));
            y = y + 1;
            ans = min(ans, abs(-D + (i*i + y*y)));
        }
    }
    cout << ans << endl;
}