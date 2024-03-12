#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(ll a, ll s) {
    if (s == 0) return a == 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ((i&j) != (a&1)) continue;
            if ((s - i - j) < 0) continue;
            if ((s -i - j)%2 != 0) continue;
            if (dfs(a >> 1, (s-i-j)>>1)) return true; 
        }
    }
    return false;
}

int main() {
    ll T; cin >> T;
    for (int i  = 0; i < T; i++) {
        ll a, s; cin >> a >> s;
        if (dfs(a, s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}