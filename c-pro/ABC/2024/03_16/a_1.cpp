#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    string S; cin >> S;
    int N = S.size();
    map<char, int> mp;
    for (int i = 0; i < N; i++) {
        mp[S[i]]++;
    }
    vector<vector<ll> > cnt(26, vector<ll>(N+1, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < N; j++) {
            if ((S[j]-'a') == i) {
                cnt[i][j+1] = cnt[i][j];
            } else {
                cnt[i][j+1] = cnt[i][j] + 1;
            }
        }
    }

    ll ans = 0;
    for (auto &it: mp) {
        if (it.second > 1) ans = 1;
    }
    for (int i = 0; i < N; i++) {
        ans += cnt[S[i]-'a'][N] - cnt[S[i]-'a'][i];
    }
    cout << ans << endl;
    return 0;
}

