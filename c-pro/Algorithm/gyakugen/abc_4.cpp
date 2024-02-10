#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod = 1000000007;

vector<int> to[10101010];
int n;

int ans;
int dfs(int v, int p = -1) {
    int res = 1;
    vector<int> ts;
    for (int u: to[v]) {
        if (u == p) continue;
        int t = dfs(u, v);
        res += t;
        ts.push_back(t);
    }
    if (p != -1) {
        ts.push_back(n - res);
    }
    int now = (pow(2, n-1)) - 1;
    for (int t: ts) {
        now -= pow(2, t)-1;
    }
    ans += now;
    return res;
}


int main() {
    int N; cin >> N;
    vector<vector<int> > tree;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    return 0;
}