#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    vector<vector<int> > dp(N+1, vector<int>(21, 0));
    dp[0][numbers[0]] = 1; 
    for (ll i = 1; i < N - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (j = numbers[i] >= 0) {
                dp[i][j] += dp[i-1][j - numbers[i]];
            }
            if (j + numbers[i] <=20) {
                dp[i][j] += dp[i-1][j + numbers[i]];
            }
        }
    }

    cout << dp[N - 2][numbers[N - 1]] << endl;
    return 0;
}