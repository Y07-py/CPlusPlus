#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string tmp = "";
    vector<string> ans;
    for (int i = 0; i < S.size(); ++i) {
        tmp += S[i];
        if (tmp == "dream") {
            if (S.substr(i+1, 2) == "er") {
                tmp += S.substr(i+1, 2);
                i += 2;
                ans.push_back(tmp);
                tmp = "";
            }
            else {
                ans.push_back(tmp);
                tmp = "";
            }
        
        } else if (tmp == "erase") {
            if (S.substr(i+1, 1) == "r") {
                tmp += S.substr(i+1, 1);
                i += 1;
                ans.push_back(tmp);
                tmp = "";
            }
            else {
                ans.push_back(tmp);
                tmp = "";
            }
        }
    }
    int count = 0;
    for (int i = 0; i < ans.size(); ++i) {
        count += ans[i].length();
    }
    if (S.size() == count) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}