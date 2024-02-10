#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, Q; cin >> n >> Q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int j = 0; j < Q; j++) {
        ll x; cin >> x;
        ll res = 0;
        int rihgt = 0;
        ll sum = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && sum + a[right] <= x) {
                sum += a[right];
                right++;
            }
            res += (right - left);
            if (right == left) ++right;
            else sum -= a[left];
        }
        cout << res << endl;
    }
    return 0;
}