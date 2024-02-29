#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > a(M);
    vector<vector<int> > pos(N);
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
        for (int j = 0; j < k; j++) {
            a[i][j]--;
            pos[a[i][j]].push_back(i);
        }
    }
    vector<int> cnt(N);
    queue<int> q;
    int take = 0;
    for (int i = 0; i < M; i++) {
        int t = a[i].back();
        cnt[t]++;
    }
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 2) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        take++;
        for (int i = 0; i < 2; i++) {
            int p = pos[x][i];
            a[p].pop_back();
            if (a[p].size()) {
                int t = a[p].back();
                cnt[t]++;
                if (cnt[t] == 2) q.push(t);
            }
        }
    }
    if (take == N) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}