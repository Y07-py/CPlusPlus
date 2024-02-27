#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<vector<int> > chars(300);
    for (int i = 0; i < S.size(); i++) {
        chars[S[i] - '0'].push_back(i+1);
    }
    for (int i = 0; i < chars.size(); i++) {
        if (chars[i].size() == 1) {
            cout << chars[i][0] << endl;
            return-0;
        }
    }
    return 0;
}