#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> sheet(H);
    for (int i = 0; i < H; ++i) {
        string tmp; cin >> tmp;
        sheet[i] = tmp;
    }
    for (int i = 0; i < H; ++i) {
        cout << sheet[i] << '\n';
        cout << sheet[i] << '\n';
    }
    return 0;
}