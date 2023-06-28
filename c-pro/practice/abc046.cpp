#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a != b) {
        ans++;
    }
    if (a != c) {
        ans++;
    }
    if (b != c) {
        ans++;
    }
    if (a == b && b == c) {
        ans++;
    }

    cout << ans << endl;

}