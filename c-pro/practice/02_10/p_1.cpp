#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limit = 1e6;

int main() {
    int N; cin >> N;
    vector<pair<int, int> > stars(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        stars[i] = make_pair(x, y);
    }
    cout << "Hello" << endl;
    int M; cin >> M;
    vector<pair<int, int> > another_stars(M);
    ll checker[limit][limit] = {0};
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        another_stars[i] = make_pair(x, y);
        checker[x][y] = 1;
    }

    pair<int, int> pointer = stars[0];
    bool judge = true;
    for (int i = 0; i < M; i++) {
        pair<int, int> p = another_stars[i];
        int dx = p.first - pointer.first;
        int dy = p.second - pointer.second;
        for (int j = 1; j < N; j++) {
            pair<int, int> p2 = stars[j];
            int p2x = p2.first + dx;
            int p2y = p2.second + dy;
            if ((0 <= p2x && p2x < limit) && (0 <= p2y && p2y < limit)) {
                if (!checker[p2x][p2y]) {
                    judge = false;
                    break;
                }
            }
        }
        if (judge) {
            cout << dx << " " << cout << dy << endl;
            break;
        }
    }
    return 0;
}