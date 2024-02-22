#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int M; cin >> M;
    vector<pair<int, int> > stars(M);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        stars[i] = make_pair(x, y);
    }
    int N; cin >> N;
    vector<pair<int, int> > another_stars(N);
    int checher[1000010][1000010] = {0};
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        another_stars[i] = make_pair(x, y);
        checher[x][y] = 1;
    }
    pair<int, int> pointer = stars[0];
    bool judge = true;
    for (int i = 0; i < N; i++) {
        pair<int, int> p = another_stars[i];
        int dx = p.first - pointer.first;
        int dy = p.second - pointer.second;
        for (int j = 1; j < M; j++) {
            pair<int, int> p2 = stars[j];
            int p2x = p2.first + dx;
            int p2y = p2.second + dy;
            if (!checher[p2x][p2y]) {
                judge = false;
                break;
            }
        }
        if (judge) {
            cout << dx << " " << dy << endl; 
        }
    }
    return 0;
}

