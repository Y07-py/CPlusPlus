#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N+1);
    vector<int> C(N+M+1);
    for (int i = 0; i < N+1; i++) cin >> A[i];
    for (int i = 0; i < N+M+1; i++) cin >> C[i];
    vector<int> B(M+1);
    for (int i = M; i > -1; i--) {
        int b = C[N+i] / A[N];
        for (int j = 0; j < N+1; j++) {
            C[i+j] -= A[j] * b;
        }
        B[i] = b;
    }
    for (int i = 0; i < M; i++) {
        cout << B[i] << " ";
    }
    cout << B[M] << endl;
    return 0;
}