#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<int, int> >  X;
    vector<ll> ans(N+1, 0);

    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        X.push_back(make_pair(a, 1));
        X.push_back(make_pair(a + b, -1));
    }

    sort(X.begin(), X.end());
    ll cnt = 0;
    for (int i = 0; i < X.size(); i++) {
        cnt += X[i].second;
        ans[cnt] += X[i+1].first - X[i].first;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i+1] << " ";
    } 
    cout << endl;
    return 0;
}