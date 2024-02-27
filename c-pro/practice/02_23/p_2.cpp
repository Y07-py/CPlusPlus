#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<int, int> > ab;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        ab.emplace_back(a, a + b);
    }
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    auto f = [&](int i, int j) -> bool {
        auto [ai, aj] = ab[i];
        auto [bi, bj] = ab[j];
        return (ll)ai*bj > (ll)aj*bi;
    };

    stable_sort(p.begin(), p.end(), f);
    for (int i = 0; i < N; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}