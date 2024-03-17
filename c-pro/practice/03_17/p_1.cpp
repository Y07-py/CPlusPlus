#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2e5+7;

int main() {
    int N; cin >> N;
    vector<int> f(N+1);
    for (int i = 0; i < N+1; i++) f[i] = i;
    for (int i = 2; i < N+1; i++) {
        int x = i*i;
        if (x > N) break;
        for (int j = x; j < N+1; j += x) {
            while (f[j]%x == 0) f[j] /= x;
        }
    }
    vector<int> C(N+1);
    ll ans = 0;
    for (int i = 1; i < N+1; i++) C[f[i]]++;
    for (int i = 0; i < N + 1; i++) ans += C[i]*C[i];
    cout << ans << endl;
    return 0;
}