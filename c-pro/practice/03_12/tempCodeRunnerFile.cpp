#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int> > AB;
int N, X;
map<pair<int, int>, bool> memo;

bool dfs(int x, int n) {
    if (n == N) return x == X;
    if (memo.find(AB[n]) != memo.end()) return memo[AB[n]];
    if (dfs(x+AB[n].first, n+1) || dfs(x+AB[n].second, n+1)) return memo[AB[n]] = true;
}

int main() {
    cin >> N >> X;
    AB.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        AB[i] = make_pair(a, b);
    }
    if (dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}