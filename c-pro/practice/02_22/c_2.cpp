#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, D; cin >> N >> M >> D;
    vector<ll> A(N);
    vector<ll> B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll res = 0;
    for (int i = 0; i < N; i++) {
        ll right = M;
        ll left = -1;

        while (right - left > 1) {
            ll mid = left - (left - right) / 2;
            if (B[mid] <= A[i]+D) left = mid;
            else right = mid;
        }
        
        if (right > 0) {
            ll b = B[right-1];
            if (abs(A[i] - b) <= D) {
                res = max(res, A[i]+b);
            }
        }
    }
    if (res == 0) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}