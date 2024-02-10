#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    string S; cin >> S;
    vector<vector<int> > op(M);
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        c--;
        op[c].push_back(i);
    }
    string res(N, '?');
    for (int i = 0; i < M; i++) {
        int size = op[i].size();
        for (int j = 0; j < size; j++) {
            res[(op[i][(j+1) % size])] = S[op[i][j]];
        }
    }
    cout << res << endl;
    return 0;
}