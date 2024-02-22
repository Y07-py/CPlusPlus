#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par;
    UnionFind() {};
    UnionFind(int n) : par(n, -1) {};
    void init(int n) {
        par.assign(n, -1);
    }

    int route(int x) {
        if (par[x] < 0) return x;
        else return par[x] = route(par[x]);
    }

    bool same(int x, int y) {
        return route(x) == route(y);
    }

    bool unit(int x, int y) {
        x = route(x), y = route(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    vector<char> B(N);
    vector<int> C(N);
    vector<char> D(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--;
        C[i]--;
    }
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        uf.unit(A[i], C[i]);
    }
    vector<int> X(N, 0);
    vector<int> Y(N, 0);
    for (int i = 0; i < N; i++) {
        X[uf.route(i)]++;
    }
    for (int i = 0; i < M; i++) {
        Y[uf.route(A[i])]++;
    }
    int x, y; x = y = 0;
    for (int i = 0; i < N; i++) {
        if (X[i] == 0) continue;
        if (X[i] == Y[i]) x++;
        else y++;
    }
    cout << x << " " << y << endl;
    return 0;
}