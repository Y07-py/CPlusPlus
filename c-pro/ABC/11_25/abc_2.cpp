#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, L, R; cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if ( L <= a && a <= R) {
            cout << a << " ";
        } else {
            if (abs(L - a) < abs(R - a)) {
                cout << L << " ";
            } else {
                cout << R << " ";
            }
        }
    }
    cout << endl;
    return 0;
}