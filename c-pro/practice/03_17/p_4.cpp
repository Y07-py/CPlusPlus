#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h1, h2, h3, w1, w2, w3; cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int ans = 0;
    for (int a = 1; a < 31; a++) {
        for (int b = 1; b < 31; b++) {
            for (int d = 1; d < 31; d++) {
                for (int e = 1; e < 31; e++) {
                    int c = h1 - a - b;
                    int f = h2 - d - e;
                    int g = w1 - a - d;
                    int h = w2 - b - e;
                    int i = w3 - c - f;
                    if (c > 0 && f > 0 && g > 0 && h > 0 && i > 0 && g+h+i == h3) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}