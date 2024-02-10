#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> sizes;

    UnionFind(int n): par(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sizes[find(x)];
    }
};

struct Edge {
    int a, b, cost;

    bool operator < (const Edge& o) const {
        return cost < o.cost;
    }
};

struct Graph {
    int n;
    vector<Edge> es;

    int kruscal() {
        sort(es.begin(), es.end());

        UnionFind uf(n);
        int min_cost = 0;
        for (int i = 0; i < es.size(); i++) {
            Edge& e = es[i];
            if (!uf.same(e.a, e.b)) {
                min_cost += e.cost;
                uf.unit(e.a, e.b);
            }
        }

        return min_cost;
    }
    
};