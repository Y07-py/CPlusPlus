#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
            tmp++;
        } else {
            tmp = 0;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}