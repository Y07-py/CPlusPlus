#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != '|') {
            if (cnt < 1 || cnt >= 2) {
                cout << S[i];
            }
        } else {
            cnt++;
        }
    }
    cout << endl;
    return 0;
}