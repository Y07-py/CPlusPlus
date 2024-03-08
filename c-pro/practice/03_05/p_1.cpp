#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    map<string , int> mp;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        string t = s;
        reverse(s.begin(), s.end());

        if (mp.find(s) != mp.end()) {
            mp[s]++;
        } else {
            mp[t]++;
        }

    }
    int ans = N;
    for (auto& itr: mp) {
        ans -= itr.second;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}