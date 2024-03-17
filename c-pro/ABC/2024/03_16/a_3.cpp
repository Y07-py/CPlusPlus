#include <bits/stdc++.h>
using namespace std;


int main() {
    string S; cin >> S;
    bool flag = true;
    for (int i = 0; i < S.size(); i++) {
        if (i == 0) {
            if (S[i] != '<') flag = false;
        }
        else if (i == S.size()-1) {
            if (S[i] != '>') flag = false;
        } else {
            if (S[i] != '=') flag = false;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
