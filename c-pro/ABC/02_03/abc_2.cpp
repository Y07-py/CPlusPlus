#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<vector<char> > Grid(H, vector<char>(W, '.'));

    int x = 0;
    int y = 0;
    int direction = 0;
    for (int i = 0; i < N; i++) {
        if (x < 0) {
            x = W - 1;
        } else if (x > W - 1) {
            x = 0;
        } else if (y < 0) {
            y = H - 1;
        } else if (y > H - 1) {
            y = 0;
        }
        if (Grid[y][x] == '.') {
            Grid[y][x] = '#';
            if (direction == 0) {
                x = x + 1;
                direction = 1;
            } else if (direction == 1) {
                y = y + 1;
                direction = 2;
            } else if (direction == 2) {
                x = x - 1;
                direction = 3;
            } else if (direction == 3) {
                y = y - 1;
                direction = 0;
            }
        } else {
            Grid[y][x] = '.';
            if (direction == 0) {
                x = x - 1;
                direction = 3;
            } else if (direction == 1) {
                y = y - 1;
                direction = 0;
            } else if (direction == 2) {
                x = x + 1;
                direction = 1;
            } else if (direction == 3) {
                y = y + 1;
                direction = 2;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << Grid[i][j];
        }
        cout << endl;
    }
    return 0;
}