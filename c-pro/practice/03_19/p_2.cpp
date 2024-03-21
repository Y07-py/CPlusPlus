#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<string> S(9);
    set<pair<int, int> > st;
    vector<pair<int, int> > pos;
    for (int i = 0; i < 9; i++) {
        cin >> S[i];
        for (int j = 0; j < 9; j++) {
            if (S[i][j] == '#') {
                st.insert(make_pair(i, j));
                pos.push_back(make_pair(i, j));
            }
        }
    }
    int N = pos.size();
    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            pair<int, int> a = pos[i];
            pair<int, int> b = pos[j];
            int di = b.first - a.first;
            int dj = b.second - a.second;
            pair<int, int> c = make_pair(b.first-dj, b.second+di);
            pair<int, int> d = make_pair(c.first-di, c.second-dj);
            if ((st.find(c) != st.end()) && (st.find(d) != st.end())) {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}