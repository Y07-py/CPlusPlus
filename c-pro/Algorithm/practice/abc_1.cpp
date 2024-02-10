#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parents;
    vector<int> rank;

    UnionFind(int size) {
        parents.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] == x) return x;
        return x = find(parents[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        if (same(x, y)) return;
        x = find(x);
        y = find(y);
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        parents[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
};

int main() {
    return 0;
}