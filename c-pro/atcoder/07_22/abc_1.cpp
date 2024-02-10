#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int flag_a = 0;
    int flag_b = 0;
    int flag_c = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            flag_a = 1;
        } else if (S[i] == 'B') {
            flag_b = 1;
        } else if (S[i] == 'C') {
            flag_c = 1;
        }
        if (flag_a + flag_b + flag_c == 3) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}