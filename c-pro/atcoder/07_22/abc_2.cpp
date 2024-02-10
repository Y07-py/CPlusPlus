#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D; cin >> N >> D;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    string first = S[0];
    string res = "";
    for (int i = 1; i < N; i++) {
        string s = S[i];
        for (int j = 0; j < D; j++) {
            if (first[j] == 'o' && s[j] == 'o') {
                res += 'o';
            } else {
                res += 'x';
            }
        }
        first = res;
        res = "";
    }
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < D; i++) {
        if (first[i] == 'o') {
            temp += 1;
        } else {
            temp = 0;
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}