#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        vector<int> a(10);
        int x = i;
        for (int j = 0; j < 4; j++) {
            int d = x % 10;
            a[d] = 1;
            x /= 10;
        }
        bool ok = true;
        for (int j = 0; j < 10; j++) {
            if (S[j] == 'o' && a[j] != 1) ok = false;
            if (S[j] == 'x' && a[j] == 1) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}