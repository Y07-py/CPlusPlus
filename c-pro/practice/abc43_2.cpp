#include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   string ans;
   for (auto e: s) {
    if (e == '0') {
        ans += '0';
    }
    else if (e == '1') {
        ans += '1';
    }
    else if (e == 'B') {
        if (ans.size() == 0) continue;
        else ans.pop_back();
    }
   }
   cout << ans << endl;

}