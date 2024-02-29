#include <bits/stdc++.h>
using namespace std;

set<string> st;

void dfs(string s, string S) {
    if (S.empty()) {
        st.insert(s);
        return;
    }
    for (int i = 0; i < S.size(); i++) {
        string ncs = S;
        ncs.erase(ncs.begin()+i);
        dfs(s+S[i], ncs);
    }
}

int main() {
    string S; cin >> S;
    int K; cin >> K;
    vector<string> res;
    dfs("", S);
    for (string s: st) {
        res.push_back(s);
    }
    sort(res.begin(), res.end());
    cout << res[K-1] << endl;
}