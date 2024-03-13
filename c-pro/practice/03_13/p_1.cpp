#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    map<int, vector<int> > mp;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        mp[y].push_back(i);
        X[i] = x;
    }
    string S; cin >> S;
    for (auto &p: mp) {
        vector<int> ids = p.second;
        vector<pair<int, char> > ps;
        for (int i: ids) {
            ps.push_back(make_pair(X[i], S[i]));
        }
        sort(ps.begin(), ps.end());
        int size = ps.size();
        for (int i = 0; i < size-1; i++) {
            if (ps[i].second == 'R' && ps[i+1].second == 'L') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}