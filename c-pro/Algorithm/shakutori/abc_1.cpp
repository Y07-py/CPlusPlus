#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, Q; cin >> n >> Q;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; i++) {
        ll x; cin >> x;
        ll res = 0;
        for (int left = 0; left < n; left++) {
            ll sum = 0;
            ll right = left;
            while (right < n && sum + A[right] <= x) {
                sum += A[right];
                right++;
            }
            res += (right - left);
        }
        cout << res << endl;
    }
    return 0;
}