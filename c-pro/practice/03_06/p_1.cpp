#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<pair<ll, ll> > XY(N);
    for (int i = 0; i < N; i++) cin >> XY[i].first >> XY[i].second;
    ll ans = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int s = j+1; s < N; s++) {
                pair<ll, ll> p1 = XY[i];
                pair<ll, ll> p2 = XY[j];
                pair<ll, ll> p3 = XY[s];

                ll l = (p3.second - p1.second) * (p2.first - p1.first);
                ll r = (p2.second - p1.second) * (p3.first - p1.first);

                if (l != r) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}