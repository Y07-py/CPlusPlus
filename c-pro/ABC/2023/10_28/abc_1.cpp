#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y; cin >> X >> Y;
    if ((Y - X) <= 2 && Y - X >= -3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}