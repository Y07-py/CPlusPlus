#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1010000000;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int res = inf;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        int j = lower_bound(B.begin(), B.end(), a) - B.begin();
        if (j < M) res = min(res, abs(a - B[j]));
        if (j >= 1) res = min(res, abs(a - B[j-1]));
    }
    cout << res << endl;
    return 0;
}