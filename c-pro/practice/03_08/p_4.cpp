#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
const int mx = 1e6;

int main() {
    ll a, N; cin >> a >> N;
    vector<ll> dist(mx, inf);
    queue<pair<ll, ll> > que;
    que.push(make_pair(0, 1));
    while (!que.empty()) {
        pair<ll, ll> p = que.front();
        que.pop();
        int v = p.second;
        ll d = p.first;
        if (ll(v*a) < mx) {
            if (dist[v*a] == inf) {
                dist[v*a] = d+1; 
                que.push(make_pair(d+1, v*a));
            }
        }
        if (v >= 10 && (v % 10) != 0) {
            string s = to_string(v);
            rotate(s.begin(), s.begin() + s.size()-1, s.end());
            int x = stoi(s);
            if (dist[x] == inf) {
                dist[x] = d+1;
                que.push(make_pair(d+1, x));
            }
        
        }
    }
    if (dist[N] == inf) {
        cout << -1 << endl;
    } else {
        cout << dist[N] << endl;
    }
    return 0;
}