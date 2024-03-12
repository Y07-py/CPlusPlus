#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    vector<int> I(N, 0);
    vector<int> J(N, 0);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'o') {
                I[i]++;
                J[j]++;
            }
        }
        S[i] = s;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                ans += (I[i] - 1) * (J[j] - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}