#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    int n = S.size();
    vector<int> x(n+1);
    for (int i = 0; i < n; i++) {
        int c = S[i] - '0';
        cout << x[i] << endl;
        x[i+1] = x[i] ^ 1<<c;
        cout << x[i+1] << endl;
    }
    map<int, int> mp;
    for (int i = 0; i < n+1; i++) {
        mp[x[i]]++;
    }
    ll ans = 0;
    for (auto p: mp) {
        ll n = p.second;
        ans += n * (n-1)/2;
    }
    cout << ans << endl;
    return 0;
}