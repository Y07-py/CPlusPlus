#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e+18

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

bool judge(ll key, ll value) {
    if (key <= value) return true;
    return false;
}

int main() {
    ll N, M, K; cin >> N >> M >> K;
    ll lcd = N * M / gcd(N, M);
    ll right = inf;
    ll left = -1;

    while (right - left > 1) {
        ll mid = left - (left - right) / 2;
        ll x = (mid / N) + (mid / M) - 2 * (mid / lcd);
        if (judge(K, x)) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}