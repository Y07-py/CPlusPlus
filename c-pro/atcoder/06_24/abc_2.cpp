#include <bits/stdc++.h>
using namespace std;

string tool(string s) {
    string res;
    for (int i = s.size()-1; i > -1; --i) {
        res += s.at(i);
    } 
    return res;
}

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S.at(i);
    }

    for (int i = 0; i < N-1; ++i) {
        string s_i = S.at(i);
        for (int j = i+1; j < N; ++j) {
            string s_j = S.at(j);
            string s_a = s_i + s_j;
            string s_b = s_j + s_i;
            if (s_a == tool(s_a) || s_b == tool(s_b)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}