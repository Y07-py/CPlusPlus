#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1LL<<60

int main() {
    ll N; cin >> N;
    vector<pair<ll, ll> > position(N);
    ll data[MAX] = {0};
    for (int i = 0; i < N; i++) {
        cin >> position[i].first >> position[i].second;
    }

    ll ans = 0;
    for (int i = 0; i < N-1; i++) {
        pair pos_1 = position[i];
        for (int j = i + 1; j < N; j++) {
            pair pos_2 = position[j];
            ll norm = sqrt(pow(pos_1.first - pos_2.first, 2) + pow(pos_1.second - pos_2.second, 2));
            data[norm] += 1;
            if (data[norm] == 4) {
                ans = max(ans, norm);
            }
        }
    }
    cout << ans * ans << endl;
    return 0;
}