#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18+7;

ll f(ll a, ll b) {
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    ll N; cin >> N;
    ll ans = inf;
    for (int a = 0; a < 1010101; a++) {
        int right = 1010101;
        int left = -1;
        while (right - left > 1) {
            int mid = left - (left - right)/2;
            if (f(a, mid) >= N) right = mid;
            else left = mid;
        }
        ans = min(ans, f(a, right));
    }
    cout << ans << endl;
    return 0;
}