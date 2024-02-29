#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll L, Q; cin >> L >> Q;
    set<int> S;
    S.insert(0);
    S.insert(L);
    
    for (int i = 0; i < Q; i++) {
        int c; cin >> c;
        ll x; cin >> x;
        if (c == 1) {
            S.insert(x);
        } else {
            auto itr = S.lower_bound(x);
            int r = *itr;
            --itr;
            int l = *itr;
            int ans = r - l;
            cout << ans << endl;
        }
    }
    return 0;
}