#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int res = 0;
    for (int i = 1; i < N + 1; i++) {
        int D; cin >> D;
        int base;
        if (i >= 10) {
            if (i / 10 != i % 10) continue;
            else base = i / 10;
        } else {
            base = i;
        }
        for (int j = 1; j <= D; j++) {
            int m = j;
            int num = m % 10;
            if (base == num) {
                if (m / 10 > 0) {
                    m /= 10;
                    if (base == m) {
                        res++;
                    }
                } else {
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}