#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int mod = 100000;

int main() {
    int N, M; cin >> N >> M;
    vector<int> house(N-1);
    vector<int> A(M);
    for (int i = 0; i < N-1; i++) {
        cin >> house[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<ll> CS(N);
    CS[0] = 0;
    for (int i = 1; i < N; i++) {
        CS[i] = CS[i-1] + house[i-1];
    }
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        int a = A[i];
        ans += abs(CS[cur + a] - CS[cur]) % mod;
        cur += a;
    }
    cout << ans % mod << endl;
    return 0;
}