#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
static const ll MAX = (1 << 30);
typedef vector<vector<int> > Vec;
typedef vector<vector<ll> > Vec_2;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll bfs(int s, int N, Vec A, Vec_2 B) {
    queue<int> qu;
    qu.push(s);
    ll ans = 0;
    vector<int> town(N, -1);
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        if (town[u] > -1) continue;
        town[u] = 1;
        ll tmp = 0;
        int v_;
        for (int& v: A[u]) {
            if (town[v] > -1) continue;
            if (tmp < B[v][u]) {
                v_ = v;
                tmp = B[v][u];
            }
        }
        qu.push(v_);
        ans += tmp;
        cout << u << endl;
    }
    cout << ans << endl;
    return ans;
} 

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > town(M);
    vector<vector<ll> > Cost(N+1, vector<ll>(N+1, -1));
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        town[a].push_back(b);
        town[b].push_back(a);
        Cost[a][b] = c;
        Cost[b][a] = c;
    }
    
    ll res = 0;
    for (int i = 0; i < N; i++) {
        chmax(res, bfs(i, N, town, Cost));
    }

    cout << res << endl;
    return 0;
}