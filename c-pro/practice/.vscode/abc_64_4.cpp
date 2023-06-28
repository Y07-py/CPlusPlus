#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isOk(ll key, ll N, vector<ll> H, ll A, ll B) {
    ll c = 0;
    for (int i = 0; i < N; ++i) {
        ll h = 1LL * H[i] - 1LL * key * B;
        if (h <= 0) continue;
        c += h / A;
        if (h % A) c++;
    }
    return c <= key;
}

int binary_search(vector<ll> A, ll N, ll a, ll b) {
    ll right = sizeof(A);
    ll left = -1;
    ll mid = left + (right - left)/ 2;
    while (right - left > 0) {
        if (isOk(mid, N, A, a, b)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    ll N, A, B; cin >> N >> A >> B;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H.at(i);
    }
    ll ng = 0, ok = 1010101010;
    ok = binary_search(H, N, A, B);
    cout << ok << endl;
    return 0;
}