#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int m; cin >> m;
    vector<pair<int, int> > stars(m);
    for (int i = 0; i < m; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    int n; cin >> n;
    vector<pair<int, int> > photo(n);
    for (int i = 0; i < n; i++) {
        cin >> photo[i].first >> photo[i].second;
    }

    vector<pair<int, int> > res(m);

    pair<int, int> first_star = stars[0];
    pair<int, int> second_star = stars[1];
    pair<int, int> data;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        int dx = photo[i].first - first_star.first;
        int dy = photo[i].second - first_star.second;
        for (int j = 0; j < m; j++) {
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (stars[j].first + dx == photo[k].first && stars[j].second + dy == photo[k].second) {
                    flag = true;
                    break;
                }
            }
            if (flag) counter++;
        }
        if (counter == m) {
            data = make_pair(dx, dy);
            break;
        }
        counter = 0;
    }
    if (counter > 0) {
        cout << data.first << " " << data.second << endl;
    }

    return 0;
}