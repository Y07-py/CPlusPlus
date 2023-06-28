#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, x; cin >> a >> b >> x;
    b = b / x + 1;
    if (a % x == 0) {
        a = a / x;
    }
    else {
        a = a / x + 1;
    }
    cout << b - a << endl;
    return 0;
}