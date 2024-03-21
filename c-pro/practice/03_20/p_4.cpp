#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 9000007;

int main() {
    int T; cin >> T;
    vector<bool> prime(inf, true);
    
    for (int i = 2; i < inf; i++) {
        if (prime[i]) {
            for (int j = i+i; j < inf; j += i) prime[j] = false;
        }
    }
    
    for (int i = 0; i < T; i++) {
        ll t; cin >> t;
        ll p = 0;
        ll q = 0;
        for (int i = 2; i*i*i <= t; i++) {
            if (t % i) continue;
            if ((t/i) % i == 0) {
                p = i;
                q = t / i / i;
            } else {
                q = i;
                p = (ll) round(sqrt(t / i));
            }
            break;
        }
        cout << p << " " << q << endl;
    }

    return 0;
}