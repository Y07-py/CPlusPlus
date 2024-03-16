#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int c, ll& ans, deque<pair<ll, ll> >& dq) {
    if (c == 0) return;
    if (c > dq.front().second) {
        ans += dq.front().first * dq.front().second;
        c -= dq.front().second;
        dq.pop_front();
        solve(c, ans, dq);
    } else if (c <= dq.front().second) {
        ans += dq.front().first * c;
        ll lc = dq.front().second - c;
        c = 0;
        ll x = dq.front().first;
        dq.pop_front();
        dq.push_front(make_pair(x, lc));
        solve(c, ans, dq);
    }
}

int main() {
    int Q; cin >> Q;
    deque<pair<ll, ll> > dq;
    for (int i = 0; i < Q; i++) {
        int n; cin >> n;
        if (n == 1) {
            ll x, c; cin >> x >> c;
            dq.push_back(make_pair(x, c));
        } else {
            int c; cin >> c;
            ll x = dq.front().first;
            ll ans = 0;
            solve(c, ans, dq);
            cout << ans << endl;
        }
    }
    return 0;
}