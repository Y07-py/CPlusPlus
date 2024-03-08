#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    ll N = S.size();
    ll K; cin >> K;
    vector<ll> cnt(N+1, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            cnt[i+1] = cnt[i] + 1;
        } else {
            cnt[i+1] = cnt[i];
        }
    }
    ll ans = 0;
    ll r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && cnt[r+1] - cnt[l] <= K) {
            r = r+1;
        }
        ans = max(ans, r-l);
    }
    cout << ans << endl;
    return 0;
}