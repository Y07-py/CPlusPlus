#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M; cin >> N >> M;
    ll ans = 0;
    if (M / 2 <= N) {
        ans = M / 2;
    } else {
        ans = N;
        M -= N * 2;
        ans += M / 4;
    }
    
    cout << ans << endl;
    return 0;
}