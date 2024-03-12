#include <bits/stdc++.h>
using namespace std;

int main() {
    int HA, WA; cin >> HA >> WA;
    vector<string> A(HA);
    for (int i = 0; i < HA; i++) cin >> A[i];
    int HB, WB; cin >> HB >> WB;
    vector<string> B(HB);
    for (int i = 0; i < HB; i++) cin >> B[i];
    int HX, WX; cin >> HX >> WX;
    vector<string> X(HX);
    for (int i = 0; i < HX; i++) cin >> X[i];
    pair<int, int> lp;
    pair<int, int> rp;
    for (int i = 0; i < HX; i++) {
        for (int j = 0; j < WX; j++) {
            if (X[i][j] == '#') {
                lp.first = min(lp.first, j);
                lp.second = min(lp.second, i);
                rp.first = max(rp.first, j);
                rp.second = max(rp.second, i);
            }
        }
    }
    int H = rp.second - lp.second + 1;
    int W = rp.first - lp.first + 1;
    vector<vector<char> > filter(H, vector<char>(W, '.'));
    for (int i = lp.second; i < rp.second + 1; i++) {
        for (int j = lp.first; j < rp.first + 1; j++) {
            filter[i - lp.second][j - lp.first] = X[i][j];
        }
    }
    vector<vector<char> > C(10, vector<char>(10, '.'));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool flag = true;
            for (int ah = 0; ah < HA; ah++) {
                for (int aw = 0; aw > WA; aw++) {
                    if (i + ah < 10 && j + aw < 10) {
                        C[i+ah][j+aw] = A[ah][aw];
                    }
                    for (int bh = 0; bh < HB; bh++) {
                        for (int bw = 0; bw > WB; bw++) {
                            if (i + bh < 10 && j + bw < 10) {
                                C[i+bh][j+bw] = B[bh][bw];
                            }
                        }
                    }
                }
            }

            for (int xh = 0; xh < H; xh++) {
                for (int xw = 0; xw < W; xw++) {
                    if (xh + i < 10 && xw + j < 10) {
                        if (C[i+xh][j+xw] != filter[xh][xw]) {
                            flag = false;
                        }
                    }
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}