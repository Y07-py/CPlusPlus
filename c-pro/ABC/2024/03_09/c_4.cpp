#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e8;

vector<vector<string> > S;
string T;
int N;
int res = inf;
map<string, int> mp;

void dfs(int n, string t, int m) {
    if (n == N) {
        if (t == T) {
            res = min(res, m);
            return;
        }
        return;
    }
    for (string s: S[n]) {
        dfs(n+1, t+s, m+1);
        dfs(n+1, t, m);
    }
}

int main() {
    cin >> T;
    cin >> N;
    vector<int> A(N);
    S.resize(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A[i] = a;
        for (int j = 0; j < a; j++) {
            string s; cin >> s;
            S[i].push_back(s);
        }
    }
    

    for (int i = 0; i < N; i++) {
        int a = A[i];
        for (int j = 0; j < a; j++) {
            string s = S[i][j];
        }
    }
    string t = "";
    dfs(0, t, 0);
    if (res == inf) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
