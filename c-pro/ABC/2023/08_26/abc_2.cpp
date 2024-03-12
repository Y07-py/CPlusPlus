#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int res = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i+1] - A[i] > 1) {
            res = A[i] + 1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}