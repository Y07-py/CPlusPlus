#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2e6+7;

int main() {
    int N; cin >> N;
    vector<int> cnt(inf, 0);
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt[a]++;
        A[i] = a; 
    }
    for (int i = 0; i < inf; i++) {
        cnt[i+1] += cnt[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += cnt[A[i]-1] * (N - cnt[A[i]]);
    }
    cout << ans << endl;
    return 0;
}