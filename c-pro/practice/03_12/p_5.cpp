#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int Q; cin >> Q;

    multiset<ll> ml;
    for (int i = 0; i < Q; i++) {
        int n; cin >> n;
        if (n == 1) {
            ll x; cin >> x;
            ml.insert(x);
            
        } else if (n == 2) {
            ll x; cin >> x;
            int k; cin >> k;
            ll ans = -1;
            auto itr = ml.upper_bound(x);
            bool flag = true;
            for (int i = 0; i < k; i++) {
                if (itr == ml.begin()) {
                    flag = false;
                    break;
                }
                itr--;
            }
            if (flag) ans = *itr;
            cout << ans << endl;
        } else {
            ll x; cin >> x;
            int k; cin >> k;
            ll ans = -1;
            auto itr = ml.lower_bound(x);
            bool flag = true;
            for (int i = 0; i < k-1; i++) {
                if (itr == ml.end()) {
                    flag = false;
                    break;
                }
                itr++;
            }
            if (flag && itr != ml.end()) ans = *itr;
            cout << ans << endl;
        }
    }
    return 0;
}