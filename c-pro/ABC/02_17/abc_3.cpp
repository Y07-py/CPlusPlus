#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N; cin >> H >> W >> N;
    string T; cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            pair<int, int> start = make_pair(j, i);
            if (S[start.second][start.first] == '#') continue;
            int nx, ny;
            bool judge = true;
            for (int t = 0; t < T.size(); t++) {
                if (T[t] == 'L') {
                    nx = start.first - 1;
                    ny = start.second;
                }
                if (T[t] == 'R') {
                    nx = start.first + 1;
                    ny = start.second;
                }
                if (T[t] == 'U') {
                    nx = start.first;
                    ny = start.second - 1;
                }
                if (T[t] == 'D') {
                    nx = start.first;
                    ny = start.second + 1;
                }

                if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                    if (S[ny][nx] == '.') {
                        start.first = nx;
                        start.second = ny;
                    } else {
                        judge = false;
                        break;
                    }
                } else {
                     judge = false;
                    break;
                }
            }
        if (judge) res++;
        }
    }
    cout << res << endl;
    return 0;
}