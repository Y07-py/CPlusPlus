#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int K; cin >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        map<char, int> cnt;
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                for (char c: S[i]) {
                    cnt[c]++;
                }
            }
        }
        for (auto& itr: cnt) {
            if (itr.second == K) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}