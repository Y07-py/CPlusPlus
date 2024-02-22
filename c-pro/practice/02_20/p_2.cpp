#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> M(H);
    for (int i = 0; i < H; i++) {
        cin >> M[i];
    }
    int N = min(H, W);
    vector<int> res(N, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int n = 1; n <= N; n++) {
                pair<int, int> center = make_pair(i, j);
                int a = center.first;
                int b = center.second;
                bool judge = true;
                if (M[a][b] == '#') {
                    for (int s = 1; s <= 2; s++) {
                        for (int t = 1; t <= 2; t++) {
                            for (int r = 1; r <= n; r++) {
                                int nx = a + pow(-1, s) * r;
                                int ny = b + pow(-1, t) * r;
                                if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                                    if (M[ny][nx] != '#') {
                                        judge = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if (!judge) break;
                    }
                    if (judge) {
                        int count = 0;
                        for (int s = 1; s <= 2; s++) {
                            for (int t = 1; t <= 2; t++) {
                                int nx = a + pow(-1, s) * N + pow(-1, s);
                                int ny = b + pow(-1, t) * N + pow(-1, t);
                                if (M[ny][nx] == '#') {
                                    count++;
                                }
                            }
                        }
                        if (count == 4) judge = false;
                    }
                    if (judge) res[n-1]++;

                }

            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}