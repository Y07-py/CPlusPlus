#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    ll size = S.size();
    string ans;
    for (int i = 0; i < size; i++) {
        ans += S[i];
        if (ans.size() >= 3 && ans.substr(ans.size()-3) == "ABC") ans.erase(ans.end()-3, ans.end());
    }
    cout << ans << endl;
    return 0;
}
