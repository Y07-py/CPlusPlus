#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<char> C(26);
    for (int i = 0; i < 26; i++) {
        C[i] = i + 'a';
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        char a, b; cin >> a >> b;
        for (int i = 0; i < 26; i++) {
            if (C[i] == a) C[i] = b;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << C[S[i]-'a'];
    }
    cout << endl;
    return 0;
}