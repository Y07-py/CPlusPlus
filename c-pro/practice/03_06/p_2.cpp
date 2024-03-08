#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<ll> > B(N, vector<ll>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            B[i][j]--;
        }
    }

    int si = B[0][0] / 7;
    int sj = B[0][0] % 7;
    if (sj + M - 1 >= 7) {
        cout<< "No" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int nb = (si+i)*7 + (sj+j);
            if (B[i][j] != nb) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}