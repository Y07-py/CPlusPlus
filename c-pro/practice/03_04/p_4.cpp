#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<> A(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A[i] = a;
        total += a;
    }
    ll X; cin >> X;
    ll P = X / total;
    ll sumb = P * total;
    ll ans = P * N;

    for (ll val: A) {
        sumb += val;
        ans++;
        if (sumb > X) {
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}