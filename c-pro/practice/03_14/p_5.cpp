#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<vector<int> > idx(N+1);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        idx[a].push_back(i);
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r, x; cin >> l >> r >> x;
        int left = lower_bound(idx[x].begin(), idx[x].end(), l-1) - idx[x].begin();
        int right = lower_bound(idx[x].begin(), idx[x].end(), r) - idx[x].begin();
        int ans = right - left;
        cout << ans << endl;
    }
    return 0;
}