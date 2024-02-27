#include <bits/stdc++.h>
using namespace std;
#define inf 2e5+1

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        if (x != 0) {
            for (int j = 2; j*j <= x; j++) {
                while (x % (j*j) == 0) {
                    x /= (j*j); 
                }
            }
        }
        cnt[x]++;
    }
    long long ans = 0;
    for (auto [p, v]: cnt) {
        if (p == 0) {
            ans += (long long)v * (N - v);
        }
        ans += (long long)v*(v-1)/2;
    }
    cout << ans << endl;
    return 0;
}