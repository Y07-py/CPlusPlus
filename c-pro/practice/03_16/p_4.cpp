#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        int x = i;
        vector<bool> judge(10, false);
         
        for (int j = 0; j < 4; j++) {
            judge[x % 10] = true;
            x /= 10;
        }
        bool flag = true;
        for (int j = 0; j < 10; j++) {
            if (S[j] == 'o' && judge[j] == false) flag = false;
            if (S[j] == 'x' && judge[j] == true) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}