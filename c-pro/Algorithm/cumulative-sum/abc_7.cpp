#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc_area(int i, int j, int k, int l, int64_t cumsum[126][126], int64_t K, int64_t V) {
    int64_t v1 = cumsum[j+1][l+1];
    v1 -= cumsum[j + 1][k] + cumsum[i][l + 1];
    v1 +=  cumsum[i][k];
    int area = (j - i + 1) * (l - k + 1);
    int64_t v2 = v1 * K * area;
    if (v2 <= V) {
        return area;
    } else {
        return -1;
    }
}

int main() {
    int64_t A_grid[125][125] = {0};
    int64_t cumsom[126][126] = {0};
    int H, W;
    int64_t K, V;
    cin >> H >> W >> K >> V;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A_grid[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int64_t tmp = A_grid[i][j];
            tmp += cumsom[i+1][j] + cumsom[i][j+1];
            tmp -= cumsom[i][j];
            cumsom[i+1][j+1] = tmp;
        }
    }
    return 0;
}