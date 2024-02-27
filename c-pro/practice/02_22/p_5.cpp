#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int binneary_search(ll value, int N, vector<ll> A) {
    int right = N;
    int left = -1;
    while (right - left > 1) {
        int mid = left - (left - right)/2;
        if (A[mid] <= value) left = mid;
        else right = mid;
    }
    return right;
}

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> sum_s(N, 0);
    for (int i = 1; i < N; i++) {
        if (i%2 == 0) {
            sum_s[i] = sum_s[i-1] + A[i] - A[i-1];
        } else {
            sum_s[i] = sum_s[i-1];
        }
    }

    int Q; cin >> Q;
    vector<pair<ll, ll> > LR(Q);
    vector<ll> ans(Q);
    for (int i = 0; i < Q; i++) {
        ll l, r; cin >> l >> r;

        int left = binneary_search(l, N, A);
        int right = binneary_search(r, N, A);
        ll res;
        if ((right-1)%2 != 0) {
            res = (r - A[right-1]);
        } else {
            res = 0;
        }
        ans[i] = res;
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
