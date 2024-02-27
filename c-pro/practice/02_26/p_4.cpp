#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e5;

struct UnionFind {
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n): par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unit(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (size(x) < size(y)) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return sizes[root(x)];
    }
    
};

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0;i < N; i++) cin >> A[i];
    UnionFind uf(M);

    for (int i = 0; i < N;i++) {
        uf.unit(A[i], A[N-i-1]);
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (uf.root(i) != i) continue;
        ans += uf.size(i)-1;
    }
    cout << ans << endl;
    return 0;
}