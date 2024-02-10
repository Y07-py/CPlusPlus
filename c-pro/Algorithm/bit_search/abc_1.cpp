#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, vector<int> > > switches(M);
    vector<int> mods(M);

    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        switches[i].first = k;
        for (int j = 0; j < k; j++) {
            int s; cin >> s;
            s--;
            switches[i].second.push_back(s);
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> mods[i];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        int tmp = 0;
        for (int i = 0; i < M; i++) {
            pair<int, vector<int> > s = switches[i];
            int count = 0;
            for (int j = 0; j < s.first; j++) {
                if (bit & (1 << s.second[j])) {
                    count++;
                }
            }
            if (count % 2 == mods[i]) {
                tmp++;
            }
        }
        if (tmp == M) ans++;
    }

    cout << ans << endl;

    return 0;
}