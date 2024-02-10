#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > people(N);

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        people[x].push_back(y);
        people[y].push_back(x);
    }

    int ans = 0;
    for (int bit = 0;  bit < (1 << N); bit++) {
        vector<int> tmp;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                int counter = 0;
                for (auto& v: tmp) {
                    for (int k = 0; k < people[v].size(); k++) {
                        if (i == people[v][k]) {
                            counter++;
                            break;
                        }
                    }
                }
                if (counter == tmp.size()) {
                    tmp.push_back(i);
                }
            }
        }
        ans = max(ans, (int)tmp.size());
    }

    if (ans == 0) ans = 1;

    cout << ans << endl;

    return 0;
}