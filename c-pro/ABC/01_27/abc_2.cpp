#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<int> array(26, 0);
    string tmp = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < S.size(); i++) {
        array[S[i] - 'a'] += 1; 
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res = max(res, array[i]);
    }
    for (int i = 0; i < 26; i++) {
        if (res == array[i]) {
            cout << tmp[i] << endl;
            break;
        }
    }
    return 0;
}