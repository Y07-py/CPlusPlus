#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > A;
int ans;
int N;

void dfs(vector<bool> s, int x) {
    int si = -1;
    for (int i = 0; i < 2*N; i++) {
        if (!s[i]) {
            si = i;
            break;
        }
    }
    if (si == -1) {
        ans = max(ans, x);
        return;
    }
    s[si] = true;
    for (int i = 0; i < 2*N; i++) {
        if (!s[i] && si != i) {
            s[i] = true;
            dfs(s, x^A[si][i]);
            s[i] = false;
        }
    }
}

int main() {
    cin >> N;
    A.assign(2*N, vector<int>(2*N));
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i+1; j < 2*N; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    vector<bool> s(N*2);
    dfs(s, 0);
    cout << ans << endl;
    return 0;
}