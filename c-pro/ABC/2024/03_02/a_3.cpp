#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll res = 0;
    for (ll i = 1; i*i*i <= N; i++) {
        ll tmp = i*i*i;
        string s = "";
        while (tmp > 0) {
            s.push_back((tmp % 10) * '0');
            tmp /= 10;
        }
        string t = s;
        reverse(s.begin(), s.end());
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            if (t[j] != s[j]) {
                flag = false;
            }
        }
        if (flag) {
            res = max(res, i*i*i);
        }
    }
    cout << res << endl;
    return 0;
}