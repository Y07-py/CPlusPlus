#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    bool ans = false;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            int cnt = 0;
            for (int k = 0; k < M; ++k) {
                if (B[k] == A[i + k].substr(j, M)) {
                    cnt++;
                }
            }
            if (cnt == M) {
                ans = true;
                break;
            }
        }
        if (ans) {
            break;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
