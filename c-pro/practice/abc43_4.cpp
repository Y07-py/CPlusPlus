#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int l = -1, r = -1;
    for (int i = 0; i+1 < S.size(); i++) {
        if (S[i] == S[i+1]) l = i+1, r = i+2;
        if (i+2 < S.size() && S[i] == S[i+2]) l = i+1, r = i+3;
    }
    cout << l << " " << r << endl;
}