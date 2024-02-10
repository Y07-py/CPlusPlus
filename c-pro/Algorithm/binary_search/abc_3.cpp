#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL >> 60
ll N;

bool isOK(vector<ll> &T, vector<ll> H, vector<ll> S, ll res) {
    bool ok = true;
    for (ll i = 0; i< N; i++) {
        if (res < H[i]) ok = false;
        else T[i] = (res - H[i]) / S[i];
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < N; i++) {
        if (T[i] < i) ok = false;
    }
    return ok;
}

ll solve(vector<ll> H, vector<ll> S, ll N) {
    ll left = 0;
    ll right = INF;
    while (right - left > 1) {
        vector<ll> T(N, 0);
        ll mid = (left + right) / 2;
        if (isOK(T, H, S, mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    ll N; cin >> N;
    vector<ll> H(N);
    vector<ll> S(N);

    for (int i = 0; i < N; i++) {
        ll h; cin >> h;
        ll s; cin >> s;
        H[i] = h;
        S[i] = s;
    }



    return 0;
}