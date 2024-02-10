#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<ll> > Scores(N, vector<ll>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Scores[i][j];
        }
    }

    ll ans = 0;
    ll tmp = 0;
    for (int j = 0; j < M-1; j++) {
        for (int s = j + 1; s < M; s++) {
            for (int i = 0; i < N; i++) {
                ll score = max(Scores[i][j], Scores[i][s]);
                tmp += score;
            }
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    
    cout << ans << endl;
    return 0;
}