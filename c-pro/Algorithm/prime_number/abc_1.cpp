#include <bits/stdc++.h>
using namespace std;

bool solve(int x) {
    if (x == 1) return false;
    for (int i = 2; i <= pow(x, 0.5); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int Q; cin >> Q;
    vector<pair<int, int> > array(Q);
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        array[i] = make_pair(l,r);
    }
    int ans = 0;
    for (int i = 0; i < Q; i++) {
        pair<int, int> area = array[i];
        int l = area.first;
        int r = area.second;
        int tmp = 0;
        for (int j = l; j <= r; j++) {
            if (j % 2 == 1) {
                if (solve(j) && j % 2 == 1) tmp++;
            }
        }
        cout << tmp << endl;
    }

    return 0;
}