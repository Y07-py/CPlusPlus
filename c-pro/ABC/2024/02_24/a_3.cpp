#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    map<char, char> M;
    map<char, char> r_M;
    for (int i = 0; i < N; i++) {
        char s = S[i];
        M[s] = s;
    }
    for (int i = 0; i < Q; i++) {
        char a, b; cin >> a >> b;
        if (r_M.find(a) == r_M.end()) {
            M[a] = b;
            r_M[b] = a;
        } else {
            M[r_M[a]] = b;
            r_M[b] = r_M[a];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << M[S[i]];
    }
    cout << endl;
    return 0;
}