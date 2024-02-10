#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL << 30


int main() {
     ll N; cin >> N;
     vector<ll> piza(N);
     for (ll i = 0; i < N; i++) cin >> piza[i];

     vector<vector<int> > dp(N, vector<int>(N));
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
     }

     
    return 0;
}