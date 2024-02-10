#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power_mod(ll n, ll k, ll mod) {
    ll result = 1;
    while (k > 0) {
        if (k & 1) result = (result * n) % mod;
        n = n * n % mod;
        k >> 1;
    }
    return result;
}

int main() {

    return 0;
}