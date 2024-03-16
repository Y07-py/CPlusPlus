#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll N, A, B; cin >>  N >> A >> B;
    ll total = (N * (N+1))/2;
    ll a = N / A;
    ll b = N / B;
    ll AB = A*B / gcd(A, B);
    ll ab = N / AB;
    ll ans = total - (A*(a*(a+1))/2 + B*(b*(b+1))/2 - (AB*(ab*(ab+1))/2));
    cout << ans << endl;
    return 0;
}