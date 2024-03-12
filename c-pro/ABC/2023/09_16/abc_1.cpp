#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B; cin >> A >> B;
    ll ans = pow(A, B) + pow(B, A);
    cout << ans << endl;
    return 0;
}