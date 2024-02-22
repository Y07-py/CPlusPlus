#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, H, K; cin >> N >> M >> H >> K;
    string S; cin >> S;
    set<pair<int, int> > item;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        item.insert(make_pair(x, y));
    }
    pair<int, int> c_p = make_pair(0, 0);
    bool judge = true;
    for (int i = 0; i < N; i++) {
        int b = S[i];
        if (b == 'R') {
            c_p.first += 1;
        } else if (b == 'L') {
            c_p.first -= 1;
        } else if (b == 'U') {
            c_p.second += 1;
        } else if (b == 'D') {
            c_p.second -= 1;
        }
        H--;
        if (H < 0) {
            judge = false;
            break;
        }
        if (item.find(c_p) != item.end()) {
            if (H < K) {
                H = K;
                item.erase(c_p);
            } 
        }
    }
    if (judge) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}