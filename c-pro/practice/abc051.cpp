#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> T_array(N);

    for (int i = 0; i < N; ++i) {
        cin >> T_array.at(i);
    }
    ll M; cin >> M;
    vector<vector<ll>> data(M);

    for (int i = 0; i < M; ++i) {
        ll P, X; cin >> P >> X;
        data.at(i) = {P, X};
    }

    for (int i = 0; i < M; ++i) {
        ll total = 0;
        for (int j = 0; j < N; ++j) {
            ll drink = data.at(i).at(1);
            ll number = data.at(i).at(0) - 1;
            ll time = T_array.at(j);
            if ( number == j) {
                total += drink;
            }
            else {
                total += time;
            }
        }
        cout << total << endl;
    }

    return 0;
}