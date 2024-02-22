#include <bits/stdc++.h>
#include <tuple>
using namespace std;
typedef long long ll;

int main() {
    ll T; cin >> T;
    vector<tuple<ll, ll, ll> > test(T);
    for (int i = 0; i < T; i++) {
        ll n, d, k; cin >> n >> d >> k;
        test[i] = make_tuple(n, d, k);
    }
    return 0;
}