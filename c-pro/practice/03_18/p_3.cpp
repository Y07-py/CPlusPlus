#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    map<string, int> mp;

    queue<string> que;
    que.push(S);
    mp[S] = 0;

    while (!que.empty()) {
        string s = que.front();
        que.pop();
        if (s == "atcoder") {
            cout << mp[s] << endl;
            break;
        }
        for (int i = 0; i < 6; i++) {
            string t = s;
            swap(t[i], t[i+1]);
            if (!mp.count(t)) {
                que.push(t);
                mp[t] = mp[s] + 1;
            }
        }
    }
    return 0;
}