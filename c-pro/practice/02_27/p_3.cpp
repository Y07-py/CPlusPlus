#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    int ans = 0;
    map<int, int> cnt;
    int now = 0;

    for (int i = 0; i < N; i++) {
        if (cnt[C[i]] == 0) now++;
        cnt[C[i]]++;
        if (i >= K) {
            cnt[C[i-K]]--;
            if (cnt[C[i-K]] == 0) now--;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}