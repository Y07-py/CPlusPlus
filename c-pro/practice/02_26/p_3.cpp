#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll tmp;
    vector<ll> A;
    map<ll, ll> cnt;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
        cnt[tmp]++;
    }
    ll res = (N*(N-1))/2;
    for (auto& it: cnt) {
        ll r = (it.second * (it.second-1))/2;
        res -= r;
    }
    cout << res << endl;
    return 0;
}