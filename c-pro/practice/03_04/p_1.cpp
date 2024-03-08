#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    set<pair<int, int> > st;
    for (int i = 0; i < N; i++) {
        st.insert(make_pair(x[i], y[i]));
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int xi = x[i], xj = x[j];
            int yi = y[i], yj = y[j];
            if (xi < xj && yi < yj) {
                pair<int, int> p1 = make_pair(xi, yj);
                pair<int, int> p2 = make_pair(xj, yi);
                if (st.find(p1) == st.end()) continue;
                if (st.find(p2) == st.end()) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}