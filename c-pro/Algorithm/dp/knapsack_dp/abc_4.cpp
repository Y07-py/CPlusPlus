#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> red(N+1);
    vector<int> blue(N+1);
    vector<int> white(N+1);
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j < N+1; j++) {
            char s; cin >> s;
            if (s == 'R') {
                blue[j]++;
                white[j]++;
            }
            if (s == 'B') {
                red[j]++;
                white[j]++;
            }
            if (s == 'W') {
                red[j]++;
                blue[j]++;
            }
            if (s == '#') {
                red[j]++;
                blue[j]++;
                white[j]++;
            }
        }
    }

    vector<vector<int> > dp(N+1, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1][0] = min(dp[i][1], dp[i][2]) + red[i+1];
        dp[i+1][1] = min(dp[i][0], dp[i][2]) + blue[i+1];
        dp[i+1][2] = min(dp[i][0], dp[i][1]) + white[i+1];
    }

    int ans = min(dp[N][0], dp[N][1]);
    ans = min(ans, dp[N][2]);
    cout << ans << endl;
    return 0;
}