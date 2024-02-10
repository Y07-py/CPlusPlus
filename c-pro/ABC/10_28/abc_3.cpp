#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool judge(ll key, ll value) {
    if (key <= value) return true;
    return false;
}

ll binary_search(vector<ll> A, ll M) {
    ll right = A.size();
    ll left = -1;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (judge(M, A[mid])) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, binary_search(A, A[i] + M) - i);
    }
    cout << ans << endl;
    return 0;
}