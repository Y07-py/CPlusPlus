#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, string> mp;
set<string> st;

bool dfs(string s) {
    if (st.find(s) != st.end()) return false;
    st.insert(s);
    if (mp.find(s) == mp.end()) return true;
    if (dfs(mp[s])) return true;
    return false;
}

int main() {
    int N; cin >> N;
    vector<string> S(N);
    vector<string> T(N);
    for (int i = 0; i < N; i++) {
        string s, t; cin >> s >> t;
        S[i] = s;
        T[i] = t;
        mp[s] = t;
    }

    for (string ss: S) {
        string ns = ss;
        while (!st.count(ns)) {
            st.insert(ns);
            auto it = mp.find(ns);
            if (it == mp.end()) break;
            ns = it -> second;
            if (ns == ss) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}