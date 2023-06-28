#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<ll>> array_a(N);
    vector<vector<ll>> array_b(M);

    for (int i = 0; i < N; ++i) {
        ll a, b; cin >> a >> b;
        array_a.at(i) = {a, b};
    }

    for (int j = 0; j < M; ++j) {
        ll c, d; cin >> c >> d;
        array_b.at(j) = {c, d};
    }

    vector<int> ans(N);

    for (int i = 0; i < N; ++i) {
        int x_1, y_1;
        x_1 = array_a[i][0];
        y_1 = array_a[i][1];
        ll min_dist = 1000000000;
        int ind;
        for (int j = 0; j < M; ++j) {
            int x_2, y_2;
            x_2 = array_b[j][0];
            y_2 = array_b[j][1];
            ll tmp_dist = abs(x_1 - x_2) + abs(y_1 - y_2);
            if (min_dist > tmp_dist) {
                ind = j + 1;
                min_dist = tmp_dist;
            }
        }
        ans[i] = ind;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans.at(i) << endl;
    }

    return 0;
}