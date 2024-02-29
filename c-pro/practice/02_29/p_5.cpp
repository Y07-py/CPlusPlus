#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, Q; cin >> L >> Q;
    set<int> st;
    st.insert(0);
    st.insert(L);

    for (int i = 0; i < Q; i++) {
        int c, x; cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto itr = st.lower_bound(x);
            int r = *itr;
            --itr;
            int l = *itr;
            int ans = r - l;
            cout << ans << endl;
        }
    }
    return 0;
}