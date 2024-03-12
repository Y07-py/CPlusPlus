#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int> > AB;
int N, X;
map<int, bool> memo;

bool dfs(int x, int n) {
    if (n == N) return x == X;
    if (memo.find(AB[n].first) != memo.end()) return memo[AB[n].first];
    if (memo.find(AB[n].second) != memo.end()) return memo[AB[n].second];
    bool res; 
    if (dfs(x+AB[n].first, n+1)) {
        res = true;
    }
    if (dfs(x+AB[n].second, n+1)) {
        res = true;
    }
    return false;
}

int main() {
    cin >> N >> X;
    AB.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        AB[i] = make_pair(a, b);
    }
    if (dfs(0, 0)) cout << "Yes" << endl;
    else cout << "NO" << endl;
    return 0;
}