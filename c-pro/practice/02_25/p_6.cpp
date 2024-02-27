#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;



int main() {
    ll N, K; cin >> N >> K;
    vector<pair<ll, ll> > a;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        a.push_back(make_pair(x, y));
    } 
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
        if (a[i].first > K) break;
        K += a[i].second;
    }
    cout << K << endl;
    return 0;
}