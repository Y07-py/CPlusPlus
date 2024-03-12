#include <bits/stdc++.h>
using namespace std;
#define INF 1e5;

int main() {
    int N, S, M, L; cin >> N >> S >> M >> L;
    vector<int> dp(N);
    int ans = INF;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int s = 0; s <= 100; s++) {
                int tmp = 6 * i + 8 * j + 12 * s;
                int tmp_m = i * S + j * M + s * L;
                if (tmp >= N) {
                    ans = min(ans, tmp_m);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}