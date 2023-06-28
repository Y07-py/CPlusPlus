#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

vector<vector<char>> field;

int main() {
    int w, h, n; cin >> w >> h >> n; 
    int x, y, a;
    int left = 0;
    int right = w;
    int up = h;
    int bottom = 0;
    rep(i, n) {
        cin >> x >> y >> a;
        if (a == 1) left = max(left, x);
        if (a == 2) right = min(right, x);
        if (a == 3) bottom = max(bottom, y);
        if (a == 4) up = min(up, y);
    }
    if (left >= right || up <= bottom) cout << 0 << endl;
    else cout << (right - left) * (up - bottom) << endl;
    return 0;
}

