#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    string S; cin >> S;
    int N = S.size();
    vector<int> cnt(26, 0);
    set<char> st;
    for (int i = 0; i < N; i++) {
        cnt[S[i]-'a']++;
        st.insert(S[i]);
    }
    
    int ans;
    if (st.size() == 1) {
        ans = 1;
    } else {
        ans = 0;
    }
    for (int i = 0; i < 25; i++) {
        for (int j = i+1; j < 26; j++) {
            ans += cnt[i] * cnt[j];
        }
    }
    cout << ans << endl;
    return 0;
}