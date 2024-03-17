#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<int> > node;
vector<int> used;

ll dis(ll x1, ll y1, ll x2, ll y2) {
    ll dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return dis;
}

bool dfs(int v, int t) {
    if (v == t) {
        return true;
    }
    used[v] = 1;
    for (int u: node[v]) {
        if (used[u]) continue;
        if (dfs(u, t)) return true;
    }
    return false;
}

int main() {
    cin >> N;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    vector<ll> X(N);
    vector<ll> Y(N);
    vector<ll> R(N);

    for (int i = 0; i < N; i++) {
        ll x, y, r; cin >> x >> y >> r;
        X[i] = x;
        Y[i] = y;
        R[i] = r;
    }
    int s;
    int t;
    node.resize(N);
    used.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ll r1 = R[i];
            ll r2 = R[j];
            ll d = dis(X[i], Y[i], X[j], Y[j]);
            if ((r1-r2)*(r1-r2) <= d && d <= (r1+r2)*(r1+r2)) {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
        if (dis(sx, sy, X[i], Y[i]) == R[i]*R[i]) {
            s = i;
        }
        if (dis(tx, ty, X[i], Y[i]) == R[i]*R[i]) {
            t = i;
        }
    }
    
    
    if (dfs(s, t)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}