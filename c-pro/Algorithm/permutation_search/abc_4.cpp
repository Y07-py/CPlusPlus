#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N; cin >> N;
    vector<int> P;
    vector<int> Q;
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    vector<int> v;
    rep(i, N) v.push_back(i + 1);
    int idx = 0, a = -1, b = -1;
    do {
        bool ok = true;
        rep(i, N) if (v[i] != P[i]) ok = false;
        if (ok) a = idx;
        ok = true;
        rep(i, N) if (v[i] != Q[i]) ok = false;
        if (ok) b = idx;
        idx++;
    } while (next_permutation(v.begin(), v.end()));

    int ans = abs(a - b);
    cout << ans << endl;
    
    return 0;
}