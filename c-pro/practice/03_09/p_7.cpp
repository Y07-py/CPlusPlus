#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    string T; cin >> T;
    int N; cin >> N;
    vector<int> A(N);
    vector<vector<string> > S(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A[i] = a;
        for (int j = 0; j < a; j++) {
            string s; cin >> s;
            S[i].push_back(s);
        }
    }
    vector<vector<int> > dp(N+1, vector<int>(T.size()+1, inf));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T.size(); j++) {
            dp[i+1][j] = dp[i][j];
        }

        for (string s: S[i]) {
            int size = s.size();
            for (int j = 0; j + size <= T.size(); j++) {
                if (T.substr(j, size) == s) {
                    dp[i+1][j + size] = min(dp[i+1][j+size], dp[i][j]+1);
                }
            }
        }
    }
    int ans = dp[N][T.size()];
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}