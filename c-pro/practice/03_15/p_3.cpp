#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e8+7;

int main() {
    int N; cin >> N;
    vector<vector<int> > cnt(10, vector<int>(10, 0));
    for (int i = 0; i  < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < 10; j++) {
            char c = s[j];
            cnt[c-'0'][j]++;
        }
    }
    int ans = inf;
    for (int i = 0; i < 10; i++) {
        int tmp = 0;
        for (int j = 0; j < 10; j++) {
            tmp = max(tmp, j + (cnt[i][j]-1)*10);
        }
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}