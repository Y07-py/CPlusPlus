#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e8
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            chmin(dp[i + j], dp[i] + abs(H[i] - H[i + j]));
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}