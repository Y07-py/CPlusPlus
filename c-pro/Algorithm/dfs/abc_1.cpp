#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
vector<int> edges[200000];
int64_t num[200000];

void dfs(int i, int p = -1) {
    for (int j: edges[i]) {
        if (j != p) {
            num[j] += num[i];
            dfs(j, i);
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < Q; i++) {
        int p, x; cin >> p >> x;
        p--;
        num[p] += x;
    }
    dfs(0);
    for (int i = 0; i < N; i++) {
        cout << num[i] << ' ';
    }
    cout << endl;
    return 0;
}