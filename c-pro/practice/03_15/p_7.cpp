#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9+7;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int r = 0; r < K; r++) {
        vector<int> b;
        for (int i = r; i < N; i += K) {
            b.push_back(A[i]);
        }
        sort(b.begin(), b.end());
        for (int i = r; i < N; i += K) {
            A[i] = b[i/K];
        }
    }
    vector<int> tmp = A;
    sort(tmp.begin(), tmp.end());
    if (tmp == A) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}