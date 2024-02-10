#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> games(N);
    for (int i = 0; i < N; i++) {
        cin >> games[i];
    }
    vector<int> counter(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (games[i][j] == 'o') {
                counter[i] += 1;
            } 
        }
    }
    vector<vector<int> > player(101, vector<int>(0));
    for (int i = 0; i < N; i++) {
        player[counter[i]].push_back(i + 1);
    }
    sort(counter.begin(), counter.end());
    for (int i = N-1; i > -1; i--) {
        for (auto e: player[i]) {
            cout << e << " ";
        }
    }
    cout << endl;
    return 0;
}