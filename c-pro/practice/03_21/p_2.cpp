#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> size;
    UnionFind(int n): par(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (x < y) swap(x, y);
        par[y] = x;
        size[x] += size[y]; 
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > node(N);
    UnionFind uf(N);
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
        if (uf.same(a, b)) ans++;
        uf.merge(a, b);
    }
    cout << ans << endl;
    return 0;
}