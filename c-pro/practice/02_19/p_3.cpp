#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2e+10

int main() {
    int N; cin >> N;
    map<ll, ll> count;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        count[a]++;
    }
    ll ans = 0;
    for (auto key = count.begin(); key != count.end(); key++) {
        ans += key->second /2 ;
    }
    cout << ans << endl;
    return 0;
}