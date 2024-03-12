#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> memo(N, 0);
    vector<int> c_s(N, 0);
    for (int i = 0; i < N-1; i++) {
        if (S[i] == S[i+1]) memo[i] = 1;
    }
    for (int i = 1; i < N; i++) {
        c_s[i] = c_s[i-1] + memo[i-1];
    }
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        cout << c_s[r-1] - c_s[l-1] << endl;
    }
}

