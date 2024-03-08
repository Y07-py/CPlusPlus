#include <bits/stdc++.h>
using namespace std;

int main() {
    string X; cin >> X;
    vector<int> new_order(26);
    for (int i = 0; i < X.size(); i++) {
        new_order[X[i] - 'a'] = i;
    }
    int N; cin >> N;
    vector<vector<int> > S(N);
    for (vector<int>& v: S) {
        string s; cin >> s;
        for (const char c: s) {
            v.push_back(new_order[c - 'a']);
        }
    }
    sort(S.begin(), S.end());
    for (auto e: S) {
        for (auto i: e) {
            cout << X[i];
        }
        cout << endl;
    }
    return 0;
}

