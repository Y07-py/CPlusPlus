#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL << 60

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    bool ok = true;

    ll left = -1;
    ll right = INF;
    ll ans;

    while (right - left > 1) {
        ll mid = (right + left) / 2;

        ll buyer = 0;
        ll boughter = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] <= mid) {
                buyer++;
            }
        }
        for (int i = 0; i < M; i++) {
            if (B[i] >= mid) {
                boughter++;
            }
        }

        if (buyer < boughter) {
            ok = false;
        } else {
            ok = true;
        }

        if (ok) {
            right = mid;
            ans = right;
        }
        else left = mid;
    }
    cout << ans << endl;
    return 0;
}