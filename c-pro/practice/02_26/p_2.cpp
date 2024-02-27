#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> S(N, 0);
    S[0] = A[0] - 1; 
    for (int i = 1; i < N; i++) {
        S[i] = A[i] - i - 1;
    }
    for (int i = 0;  i< Q; i++) {
        ll k; cin >> k;

        int r = lower_bound(S.begin(), S.end(), k) - S.begin();
        ll ans;
        if (r == 0) {
            ans = k;
        } else {
            ans = A[r-1] + (k - S[r-1]);
        }
        cout << ans << endl;
    }
    return 0;
}