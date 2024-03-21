#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool judge(char a, char b) {
    return a == '?' || b == '?' || a == b;
}

int main() {
    string S; cin >> S;
    string T; cin >> T;
    int N = T.size();
    vector<bool> pre(N+1, false);
    vector<bool> suf(N+1, false);
    pre[0] = true;
    for (int i = 0; i < N; i++) {
        if (judge(S[i], T[i])) pre[i+1] = true;
        else break;
    }
    suf[0] = true;
    for (int i = 0; i < N; i++) {
        if (judge(S[S.size()-i-1], T[T.size()-1-i])) suf[i+1] = true;
        else break;
    }
    for (int i = 0; i < N+1; i++) {
        if (pre[i] && suf[N-i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}