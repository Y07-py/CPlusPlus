#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    set<ll> st;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        st.insert(a);
    }
    for (int i = 0; i < K; i++) {
        if (st.find(i) == st.end()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << K << endl;
    return 0;
}