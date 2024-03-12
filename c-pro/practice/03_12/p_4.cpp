#include <bits/stdc++.h>
using namespace std;

int main() {
    const int di[4] = {0, 1, 1, -1};
    const int dj[4] = {1, 0, 1, 1};
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int v = 0; v < 4; v++) {
                int ni = i, nj = j;
                int cnt = 0;
                for (int k = 0; k < 6; k++) {
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                        cnt = 999;
                        break;
                    }
                    if (S[ni][nj] == '.') cnt++;
                    ni += di[v]; 
                    nj += dj[v];
                }
                if (cnt <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}