#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> T_array(N);
    for (int i = 0; i < N; ++i) {
        cin >> T_array[i];
    }
    ll total = T;
    for (int i = 1; i < N; ++i) { 
        total += min(T, T_array[i] - T_array[i-1]);
    }
    cout << total << endl;
    return 0;
}