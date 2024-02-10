#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> C(N);
    vector<vector<int> >A(N);
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    int X; cin >> X;
    vector<pair<int, int> > results;
    for (int i = 0; i < N; i++) {
        int size = A[i].size();
        for (int j = 0; j < size; j++) {
            if (X == A[i][j]) {
                results.push_back(make_pair(size, i));
                break;
            }
        }
    }
    if (results.empty()) {
        cout << 0 << endl;
        return 0;
    }
    sort(results.begin(), results.end());
    pair<int, int> first = results[0];
    int counter = 1;
    vector<int> ans;
    ans.push_back(first.second);
    for (int i = 1; i < results.size(); i++) {
        if (first.first == results[i].first) {
            counter++;
            ans.push_back(results[i].second);
        }
    }
    cout << counter << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}