#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isOK(ll value, ll key) {
    if (value > key) return true;
    return false;
}

ll solve(vector<ll> array, ll N, ll key) {
    ll left = -1;
    ll right = N;
    while (right - left > 1) {
        ll mid = left + (right - left)/2;
        if (isOK(array.at(mid), key)) right = mid;
        else left = mid;
    }
    return right;
}

bool isOK_2(ll value, ll key) {
    if (value < key) return true;
    return false;
} 

ll solve_2(vector<ll> array, ll N, ll key) {
    ll left = -1;
    ll right = N;
    while (right - left > 1) {
        ll mid = left + (right - left)/2;
        if (isOK_2(array.at(mid), key)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(C.begin(), C.end());

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ll rep = B[i];
        ll pre_ = solve_2(A, N, rep);
        ll next_ = solve(C, N, rep);
        ans += (N - pre_) * (N - next_);
    }
    cout << ans << endl;
    return 0;
}