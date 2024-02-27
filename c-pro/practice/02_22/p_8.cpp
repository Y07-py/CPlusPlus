#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> count(N, 0);
    deque<char> ans;
    stack<char> checker;
    for (int i = 0; i < N; i++) {
        if (S[i] != ')') {
            ans.push_back(S[i]);
            if (S[i] == '(') {
                checker.push(S[i]);
            }
        } else {
            if (checker.empty()) {
                ans.push_back(S[i]);
            } else {
                while (-1) {
                    char c = ans.back();
                    ans.pop_back();
                    if (c == '(') break;
                }
                checker.pop();
            }
        }
    }
    while (!ans.empty()) {
        cout << ans.front();
        ans.pop_front();
    }
    cout << endl;
    return 0;
}