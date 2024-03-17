#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9+7;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<pair<int, char> > W(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        W[i] = make_pair(w, S[i]);
        if (S[i] == '1') ans++;
    }
    sort(W.begin(), W.end());
    int tmp = ans;
    for (int i = 0; i < N; i++) {
        if (W[i].second == '1') tmp--;
        else tmp++;
        if (i < N-1) {
            if (W[i].first != W[i+1].first) ans = max(ans, tmp);
        } else {
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}