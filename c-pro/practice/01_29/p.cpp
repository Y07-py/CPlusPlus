#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9;

int main() {
    int N; cin >> N;
    vector<int> Q(N);
    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                int q; cin >> q;
                Q[j] = q;
            }
            if (i == 1) {
                int a; cin >> a;
                A[j] = a;
            }
            if (i == 2) {
                int b; cin >> b;
                B[j] = b;
            }
        }
    }
    
    int range = INF;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            continue;
        }
        range = min(range, Q[i] / A[i]);
    }
    int res = 0;
    for (int i = 0; i < range + 1; i++) {
        int tmp = INF;
        for (int j = 0; j < N; j++) {
            if (Q[j] - A[j] * i >= 0) {
                if (B[j] == 0) {
                    continue;
                }
                tmp = min(tmp, (Q[j] - A[j] * i) / B[j]);
            }
        }
        int total = i + tmp;
        res = max(res, total);
    }
    cout << res << endl;
    return 0;
}