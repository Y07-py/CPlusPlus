#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1LL << 60

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> heights(N);

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    ll res = MAX;
    for (int bit = 0; bit < (1 << N); bit++) {
        ll tmp = 0;
        ll count = 0;
        bool flag = false;
        ll highest = 0;
        vector<ll> copy = heights;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                flag = true;
                if (i > 0) {
                    if (heights[0] >= copy[i]) {
                        tmp += heights[0] - copy[i] + 1;
                        copy[i] += heights[0] - copy[i] + 1;
                    }
                    if (copy[i-1] >= copy[i]) {
                        tmp += copy[i-1] - copy[i] + 1;
                        copy[i] += copy[i-1] - copy[i] + 1;
                    }
                    if (highest >= copy[i]) {
                        tmp += highest - copy[i] + 1;
                        copy[i] += highest - copy[i] + 1;
                    }
                    count++;
                } else {
                    count++;
                }
            }
            highest = max(highest, copy[i]);
        }
        if (count >= K && flag) res = min(res, tmp);
    }

    cout << res << endl;
    return 0;
}