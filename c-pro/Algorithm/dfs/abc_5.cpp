#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Tree = vector<vector<int> >;

int N, Q;
vector<int> nodes(N+1, 0);
vector<ll> counter(N+1, 0);

void dfs(int p, Tree& T, int x) {
    nodes[p] = 1;
    counter[p] += x;
    for (auto& v: T[p]) {
        if (nodes[v] != 0) continue;
        dfs(v, T, x);
    }
    nodes[p] = 0;
}

int main() {
    cin >> N >> Q;
    Tree T(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        T[a].push_back(b);
    }
    for (int i = 0; i < N; i++) counter[i] = 0;
    for (int i = 0; i < Q; i++) {
        int p, x; cin >> p >> x;
        p--;
        dfs(p, T, x);
    }
    for (int i = 0; i < N; i++) {
        cout << counter[i] << " ";
    }
    cout << endl;
    return 0;
}