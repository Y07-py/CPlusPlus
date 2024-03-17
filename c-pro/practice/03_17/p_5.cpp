#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<int, int> > LR(N);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        LR[i] = make_pair(r, l);
    }
    sort(LR.rbegin(), LR.rend());
    vector<pair<int, int> > res;
    int r = LR[0].first;
    int l = LR[0].second;
    for (int i = 1; i < N; i++) {
        if (LR[i].first < l) {
            res.push_back(make_pair(l, r));
            r = LR[i].first;
            l = LR[i].second;
        } else {
            if (LR[i].second < l) {
                l = LR[i].second;
            }
        }
    }
    res.push_back(make_pair(l, r));
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl; 
    }
    return 0;
}