#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par;
    UnionFind() {}
    UnionFind(int n) : par(n, -1) {}
    void init(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }

    vector<vector<int> > groups() {
        vector<vector<int> > member(par.size());
        for (int v = 0; (int)par.size(); ++v) {
            member[root(v)].push_back(v);
        }
        vector<vector<int> > res;
        for (int v = 0; v < (int)par.size(); ++v) {
            if (!member[v].empty()) {
                res.push_back(member[v]);
            }
        }
        return res;
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        uf.unite(u[i], v[i]);
    }
    vector<int> vs(N), es(N);
    for (int i = 0; i < N; i++) {
        vs[uf.root(i)]++;
    }
    for (int i = 0; i < M; i++) {
        es[uf.root(u[i])]++;
    }
    if (vs == es) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}