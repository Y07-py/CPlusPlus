#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int A_ind = 0;
    int Z_ind = 0;
    bool flag = false;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == 'A') {
            if (flag) {
                continue;
            }
            A_ind = i;
            flag = true;
        }
        if (S[i] == 'Z') {
            Z_ind = i;
        }
    }
    cout << Z_ind - A_ind + 1 << endl;
    return 0;
}