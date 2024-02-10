#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    bool flag = true;
    for (int i = 1; i < 16; i++) {
        if ((i + 1) % 2 == 0) {
            if (S[i] - '0' != 0) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}