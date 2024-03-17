#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll X; cin >> X;
    ll ans;
    if (X >= 0) {
        ans = (X+10-1)/10;
    } else {
        ans = (X)/10;
    }
    cout << ans << endl;
    return 0;
}