#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        vector<int> checker(10, 0);
        int d = i;
        for (int j = 0; j < 4; j++) {
            int s = d % 10;
            d /= 10;
            checker[s] = 1;
        }
        bool ok = true;
        for (int j = 0; j < 10; j++) {
            if (S[j] == 'o' && checker[j] != 1) ok = false;
            if (S[j] == 'x' && checker[j] == 1) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}