#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, D; cin >> M >> D;
    int y, m, d; cin >> y >> m >> d;

    if (d + 1 > D) {
        int n_m = m + 1;
        if (n_m > M) {
            cout << y+1 << " " << 1 << " " << 1 << endl;
        } else {
            cout << y << " " << n_m << " " << 1 << endl;
        }
    } else {
        cout << y << " " << m << " " << d + 1 << endl;
    }
    return 0;
}