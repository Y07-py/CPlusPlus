#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b; cin >> r >> g >> b;
    int n = 10 * g + b;
    if (n % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}