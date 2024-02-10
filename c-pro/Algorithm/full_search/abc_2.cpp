#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int s = 0; s< 10 ;  s++) {
                string tmp;
                tmp += to_string(i) + to_string(j) + to_string(s);
                int ti = 0;
                int si = 0;
                while (si < N && ti < 3) {
                    if (S[si] == tmp[ti]) {
                        si++;
                        ti++;
                    } else {
                        si++;
                    }
                }
                if (ti == 3) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}