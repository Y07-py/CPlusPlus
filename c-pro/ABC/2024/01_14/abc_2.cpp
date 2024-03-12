#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string res;
    
    while (N > 1) {
        int mod = N % 2;
        if (mod == 0) {
            res += '0';
        } else {
            res += '1';
        }
        N /= 2;
    }
    res += '1';
    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == '0') {
            ans += 1;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}