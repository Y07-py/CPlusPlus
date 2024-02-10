#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int> > field(N, vector<int>(4));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> field[i][j];
        }
    }
    vector<vector<int> > area(101, vector<int>(101, 0));
    for (int i = 0; i < N; i++) {
        int x_1, x_2, y_1, y_2;
        x_1 = field[i][0];
        x_2 = field[i][1];
        y_1 = field[i][2];
        y_2 = field[i][3];
        for (int y = y_1; y < y_2; y++) {
            for (int x = x_1; x < x_2; x++) {
                if (area[y][x] == 0){
                    area[y][x] = 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (area[i][j]) res++;
        }
    }
    cout << res << endl;
    return 0;
}