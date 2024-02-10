#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    string res;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '.') {
            res = "";
            for (int j = i + 1; j < S.size(); j++) {
                if (S[j] != '.') {
                    res += S[j];
                } else {
                    break;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}