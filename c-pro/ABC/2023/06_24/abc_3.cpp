#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H_a, W_a;
    int H_b, W_b;
    int H_x, W_x;
    cin >> H_a >> W_a;
    vector<string> A(H_a);
    for (int i = 0; i < H_a; ++i) {
        cin >> A.at(i);
    }
    cin >> H_b >> W_a;
    vector<string> B(H_b);
    for (int i = 0; i < H_b; ++i) {
        cin >> B.at(i);
    }
    cin >> H_x >> W_x;
    vector<string> X(H_x);
    for (int i = 0; i < H_x; ++i) {
        cin >> X.at(i);
    }
    
    int d_w, d_h;
    d_w = max(W_x - W_a, 0);
    d_h = max(H_x - H_a, 0);

    vector<string> base_map(100);
    char dot = '.';
    for (int i = 0; i < 100; ++i) {
        string s = "";
        for (int j = 0; j < 100; ++j) {
            base_map[i][j] = dot;
        }
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            bool flag = false;
            for (int h_a = 0; h_a < H_a; ++h_a) {
                for (int w_a = 0; w_a < W_a; ++w_a) {
                    base_map[i+h_a][j+w_a] = A[h_a][w_a];
                }
            }
            for (int h_b = 0; h_b < H_b; ++h_b) {
                for (int w_b = 0; w_b < W_b; ++w_b) {
                    if (B[h_b][w_b] == '#') {
                        if (base_map[i+h_b][j+w_b] == '.') {
                            base_map[i+h_b][j+w_b] = B[h_b][w_b];
                        }
                    }
                }
            }
            for (int h_x = 0; h_x < H_x; ++h_x) {
                for (int w_x = 0; w_x < W_x; ++w_x) {
                    if (base_map[i+h_x][j+w_x] != X[h_x][w_x]) {
                        flag = true;
                        break;
                    }
                    cout << base_map[i+h_x][j+w_x];
                }
                cout << endl;
                if (flag) break;
                else {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}