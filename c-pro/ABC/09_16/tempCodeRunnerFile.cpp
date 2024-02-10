include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<char> r_S;
    int leng = S.size() - 1;
    for (int i = leng-1; i > -1; i--) {
        r_S.push_back(S[i]);
    }
    int tmp = 1;
    int ans = 1;
    for (int i = 0; i < leng; i++) {
        if (S[i] != r_S[i]) {
            tmp = 1;
            continue;
        }
        tmp++;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}