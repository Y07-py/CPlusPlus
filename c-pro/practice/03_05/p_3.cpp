#include <bits/stdc++.h>
using namespace std;

// 0: Win, 1: lose, 2: draw

bool judge(char a, char b) {
    if (a == 'G' && b == 'C') return true;
    if (a == 'C' && b == 'P') return true;
    if (a == 'P' && b == 'G') return true;
    return false;
}

int main() {
    int N, M; cin >> N >> M;
    vector<string> A(2*N);
    vector<pair<int, int> > res(2*N);
    for (int i = 0 ; i < 2 * N; i++) {
        string s; cin >> s;
        A[i] = s;
        res[i] = make_pair(0, i);
    }
    for (int round = 0; round < M; round++) {
        for (int i = 0 ; i < 2*N; i += 2) {
            int p1 = res[i].second;
            int p2 = res[i+1].second;

            if (judge(A[p1][round], A[p2][round])) res[i].first--;
            if (judge(A[p2][round], A[p1][round])) res[i+1].first--;
        }
        sort(res.begin(), res.end());
    }
    for (int i = 0; i < 2*N; i++) {
        cout << res[i].second + 1 << endl;
    }
    return 0;
}