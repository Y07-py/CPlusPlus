#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> counter(26,0);
    int index = 0;
    while (index < N) {
        char e = S[index];
        int tmp = 1;
        int tmp_index = index + 1;
        while (tmp_index < N && S[tmp_index] == S[index]) {
            tmp += 1;
            tmp_index += 1;
        }
        index = tmp_index;
        counter[e - 'a'] = max(tmp, counter[e - 'a']);
    };
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += counter[i];
    }
    cout << ans << endl;
    return 0;
}