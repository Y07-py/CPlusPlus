#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int Q; cin >> Q;
    ll add = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    vector<ll> res;
    for (int i = 0; i < Q; i++) {
        int j; cin >> j;
        ll x;
        if (j == 1) {
            cin >> x;
            pq.push(x - add);
        } else if (j == 2) {
            cin >> x;
            add += x;
        } else {
            x = pq.top();
            pq.pop();
            cout << x + add << endl;
        }
    }
    return 0;
}