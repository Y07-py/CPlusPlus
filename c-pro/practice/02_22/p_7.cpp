#include <bits/stdc++.h>
using namespace std;

int main() {
    int h_a, w_a; cin >> h_a >> w_a;
    int count = 0;
    vector<string> A(h_a);
    for (int i = 0; i < h_a; i++) { cin >> A[i]; 
        for (int j = 0; j < w_a; j++) {
            if (A[i][j] == '#') count++;
        }
    }
    int h_b, w_b; cin >> h_b >> w_b;
    vector<string> B(h_b);
    for (int i = 0; i < h_b; i++) { cin >> B[i]; 
        for (int j = 0; j < w_b; j++) {
            if (B[i][j] == '#') count++;
        }
    }
    int h_x, w_x; cin >> h_x >> w_x;
    int count_x = 0;
    vector<string> X(h_x);
    for (int i = 0; i < h_x; i++) {
        cin >> X[i];
        for (int j = 0; j < w_x; j++) {
            if (X[i][j] == '#') count_x++;
        }
    }

    for (int i_a = 0; i_a < 10; i_a++) {
        for (int j_a = 0; j_a < 10; j_a++) {
            for (int i_b = 0; i_b < 10; i_b++) {
                for (int j_b = 0; j_b < 10; j_b++) {

                    vector<vector<char> > C(10, vector<char>(10, '.'));
                    for (int y_a = 0; y_a < h_a; y_a++) {
                        for (int x_a = 0; x_a < w_a; x_a++) {
                            char a = A[y_a][x_a];
                            if (i_a + y_a < 10 && j_a + x_a < 10) {
                                C[i_a+y_a][j_a+x_a] = a;
                            }
                        }
                    }

                     for (int y_b = 0; y_b < h_b; y_b++) {
                        for (int x_b = 0; x_b < w_b; x_b++) {
                            char b = B[y_b][x_b];
                            if (i_b + y_b < 10 && j_b + x_b < 10) {
                                C[i_b+y_b][j_b+x_b] = b;
                            }
                        }
                    }

                    bool judge = true;
                    int res = 0;
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 10; j++) {
                            if (C[i][j] == '#') res++;
                        }
                    }
                    for (int y_x = 0; y_x < h_x; y_x++) {
                        for (int x_x = 0; x_x < w_x; x_x++) {
                            if (C[y_x][x_x] != X[y_x][x_x]) {
                                judge = false;
                            }
                        }
                    }

                    if (judge) {   
                        if (res == count_x) { 
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                } 
            }
        }
    }
    cout << "No" << endl;
    return 0;
}