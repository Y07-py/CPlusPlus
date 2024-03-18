#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> PQR;
    ll N; cin >> N;
    for (int i = 0; i < 3; i++) {
        ll p; cin >> p;
        PQR.push_back(p);
    }
    vector<int> A(N);
    set<ll> st;
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
    for (int i = 0; i < N+1; i++) st.insert(S[i]);

    for (int x = 0; x < N+1; x++) {
        ll sx = S[x];
        bool flag = true;
        for (int i = 0; i < 3; i++) {
            sx += PQR[i];
            if (st.find(sx) == st.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}