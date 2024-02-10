#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<int> X(M);
    for (int &i: X) {
        cin >> i;
        i--;
    }
    vector<ll> v(N+1);
    auto dist = [&](int from, int to) {
        if (from <= to) return to - from
        else return to + N - from;
    };
    auto add = [&](int from, int to, int num) {
        if (from <= to) {
            v[from] += num;
            v[to] -= num;
        } else {
            v[from] += num;
            v[N] -= num;
            v[0] += num
            v[to] -= num;
        }
    };
    for (int i = 0; i < M - 1; i++) {
        add(X[i], X[i + 1], dist(X[i+1], X[i]));
        add(X[i+1], X[i], dist(X[i], X[i+1]));
    }
    ll ans = 1LL << 60;
    for (int i = 0; i < N; i++) {
        v[i+1] += v[i];
        ans = min(ans, v[i]);
    }
    cout << ans << endl;
    return 0;
}