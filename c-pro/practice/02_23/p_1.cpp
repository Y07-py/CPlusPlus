#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<long double, int> > AB(N); 
    for (int i = 0; i < N; i++) {
        double a, b; cin >> a >> b;
        AB[i] = make_pair(a/(a+b), i+1); 
    }
    sort(AB.begin(), AB.end());
    map<long double, vector<int> > judge;
    for (int i = 0; i < N; i++) {
        judge[AB[i].first].push_back(AB[i].second);
    }
    for (int i = AB.size()-1; i > -1; i--) {
        if (judge[AB[i].first].size() > 1) {
            stable_sort(judge[AB[i].first].begin(), judge[AB[i].first].end());
            for (int j = 0; j < judge[AB[i].first].size(); j++) {
                cout << judge[AB[i].first][j] << " ";
                i--;
            }
            auto it = judge.find(AB[i].first);
            judge.erase(it);
        } else {
            cout << AB[i].second << " ";
        }
    }
    cout << endl;
    return 0;
}