#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> table(N, 0);
    for (int i = 0; i < N; i++) {
        int j = (P[i]-1-i+N)%N;
        for (int k = 0; k < 3; k++) {
            table[(j+k)%N]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, table[i]);
    }
    cout << ans << endl;
    return 0;
}