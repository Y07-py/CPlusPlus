#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9+7;

int main() {
    int Q; cin >> Q;
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < Q; i++) {
        int n; cin >> n;
        if (n == 1) {
            int x; cin >> x;
            st.insert(x);
            mp[x]++;
        } else if (n == 2) {
            int x, c; cin >> x >> c;
            int cnt = min(c, mp[x]);
            mp[x] -= cnt;
            if (mp[x] == 0) {
                st.erase(x);
            }
        } else {
            cout << *st.rbegin() - *st.begin() << endl;
        }
    }
    return 0;
}