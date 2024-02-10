#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    string S; cin >> S;
    string T; cin >> T;
    bool flag_1 = false;
    bool flag_2 = false;
    for (int i = 0; i <= M-N; i++) {
        flag_1 = false;
        for (int j = 0; j < N; j++) {
            if (T[i + j] != S[j]) {
                flag_1 = false;
                break;
            }
            flag_1 = true;
        }
        if (flag_1) {
            break;
        }
    }
    for (int i = M - N; i > -1; i--) {
        flag_2 = false;
        for (int j = 0; j < N; j++) {
            if (T[i + j] != S[j]) {
                flag_2 = false;
                break;
            }
            flag_2 = true;
        }
        if (flag_2) break;
    }
    int ans = 0;
    if (flag_1 && flag_2) {
        ans = 0;
    } else if (flag_1 && !flag_2) {
        ans = 1;
    } else if (!flag_1 & flag_2) {
        ans = 2;
    } else {
        ans = 3;
    }
    cout << ans << endl;
    return 0;
}