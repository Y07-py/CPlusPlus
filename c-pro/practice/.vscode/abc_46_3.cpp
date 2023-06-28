#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int counter = 0;
    int pro = 0;
    int gray = 0;
    int brown = 0;
    int green = 0;
    int wblue = 0;
    int blue = 0;
    int yellow = 0;
    int dir = 0;
    int red = 0;

    for (int i = 0; i < N; ++i) {
        if (1 <= A[i] && A[i] <= 399) {
            if (gray == 0) {
                ++gray;
            }
        } else if (400 <= A[i] && A[i] <= 799) {
            if (brown == 0) {
                ++brown;
            }
        } else if (800 <= A[i] && A[i] <= 1199) {
            if (green == 0) {
                ++green;
            }
        } else if (1200 <= A[i] && A[i] <= 1599) {
            if (wblue == 0) {
                ++wblue;
            }
        } else if (1600 <= A[i] && A[i] <= 1999) {
            if (blue == 0) {
                ++blue;
            }
        } else if (2000 <= A[i] && A[i] <= 2399) {
            if (yellow == 0) {
                ++yellow;
            }
        } else if (2400 <= A[i] && A[i] <= 2799) {
            if (dir == 0) {
                ++dir;
            }
        } else if (2800 <= A[i] && A[i] <= 3199) {
            if (red == 0) {
                ++red;
            }
        } else if (3200 <= A[i]) {
            ++pro;
        }
    }
    int total = gray + green + brown + wblue + blue + yellow + dir + red;
    if (pro >= 1 && pro < N) {
        cout << total << ' ' << total+pro << endl;
    } else if (pro == 0) {
        cout << total << ' '  << total << endl;
    } else if (pro == N) {
        cout << 1 << ' ' << N << endl;
    }
    return 0;
}