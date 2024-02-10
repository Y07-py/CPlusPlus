#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int INF = (1 << 21);

int N;
vector<pair<pair<int, int>, int> > town(N);

struct UnionFind {
    vector<int> parents;
    vector<int> sizes;

    UnionFind(int N): parents(N), sizes(N, 1) {
        for (int i = 0; i < N; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        parents[y] = x;
        sizes[x] += sizes[y];
    }

    bool issame(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sizes[find(x)];
    }
};


int main() {
    cin >> N;
    vector<pair<int, int> > X(N);
    vector<pair<int, int> > Y(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
    }
    vector<tuple<int, int, int> > edges;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 0; i < N-1; i++) {
        edges.push_back(make_tuple(X[i+1].first - X[i].first, X[i].second, X[i+1].second));
        edges.push_back(make_tuple(Y[i+1].first - Y[i].first, Y[i].second, Y[i+1].second));
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    int ans = 0;

    for (auto& e: edges) {
        int x, y, c;
        tie(c, x, y) = e;

        if (!uf.issame(x, y)) {
            uf.unite(x, y);
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}