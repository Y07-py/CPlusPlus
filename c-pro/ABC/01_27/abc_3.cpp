#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<vector<int> > array(3, vector<int>(N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int r; cin >> r;
            array[i][j] = r;
        }
    }
    int res = 0;
    int max_A = 0;
    int max_B = 0;
    vector<int> Q[0];
    bool judge_A = true;
    for (int i = 0; i < N; i++) {
        if (Q[i] - Q[1][i] < 0) {
            judge_A = false;
            break;
        }
        Q[i] -= Q[1][i];
        max_A += 1;
    }
    if (judge_A) {
        
    }

    for (int bit = 0; bit < (1 << N); bit++) {

    }
    cout << res << endl;
    return 0;
}