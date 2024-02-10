#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    string T; 
    cin >> N >> T;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<ll> ans;
    for (int i = 0; i < N; i++) {
        string s = S[i];
        if (s == T) {
            ans.push_back(i+1);
        } else {
            if (s.size() == T.size() + 1) {
                int counter_1 = 0;
                for (int j = 0; j < T.size(); j++) {
                    if (s[j] != T[j]) counter_1++;
                }
                if (counter_1 <= 2) {
                    ans.push_back(i+1);
                }
            } else if (s.size() == T.size() - 1) {
                int counter_2 = 0;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] == T[j]) counter_2++;
                }
                if (counter_2 <= 0) {
                    ans.push_back(i+1);
                }
            } else if (s.size() == T.size()) {
                int counter_4 = 0;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] != T[j]) {
                        counter_4++;
                    }
                }
                if (counter_4 == 1) {
                    ans.push_back(i+1);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}