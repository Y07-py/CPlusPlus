#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S[0] < 'A' || S[0] > 'Z') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < S.length(); i++) {
        if (S[i] < 'a' || S[i] > 'z') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}