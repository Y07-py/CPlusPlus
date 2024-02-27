#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    ll ans = 0;
    map<int, int> cnt;
    ll now = 0;

    for (int i = 0; i < N; i++) {
        if (cnt[C[i]] == 0) {
            now++;
        }
        cnt[C[i]]++;
        if (i >= K) {
            cnt[C[i]]--;
            if (cnt[C[i-K-1]] == 0) now--;
        }
        ans = max(now, ans);
    }
    cout << ans << endl;
    return 0;
}