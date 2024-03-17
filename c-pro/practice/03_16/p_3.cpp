#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    ll total = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        total += b;
        pq.push(p);
    }
    ll ans = 1;
    ll pass = 0;
    while (total > K) {
        pair<int, int> p = pq.top();
        pq.pop();
        total -= p.second;
        ans += p.first - pass;
        pass += p.first - pass;
    }
    cout << ans << endl;
    return 0;
}