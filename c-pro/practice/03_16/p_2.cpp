#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e6+7;

vector<vector<char> > normalize(int H, int W, vector<string> S) {
    pair<int, int> m = make_pair(inf, inf);
    pair<int, int> M = make_pair(0, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                m.first = min(m.first, j);
                m.second  = min(m.second, i);
                M.first = max(M.first, j);
                M.second = max(M.second, i);
            }
        }
    }
    int W_ = M.first - m.first + 1;
    int H_ = M.second - m.second + 1;
    vector<vector<char> > I(H_, vector<char>(W_, '.'));
    for (int i = m.second; i < M.second+1; i++) {
        for (int j = m.first; j < M.first+1; j++) {
            I[i - m.second][j - m.first] = S[i][j];
        }
    }
    return I;
}

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

    vector<vector<char> > IA = normalize(HA, WA, A);
    vector<vector<char> > IB = normalize(HB, WB, B);
    vector<vector<char> > IX = normalize(HX, WX, X);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            vector<vector<char> > C(21, vector<char>(21, '.'));
            for (int ay = 0; ay < IA.size(); ay++) {
                for (int ax = 0; ax < IA[0].size(); ax++) {
                    if (i+ay < 20 && j+ax < 20) {
                        C[i+ay][j+ax] = IA[ay][ax];
                    }
                }
            }
            for (int s = 0; s < 20; s++) {
                for (int t = 0; t < 20; t++) {
                    for (int by = 0; by < IB.size(); by++) {
                        for (int bx = 0; bx < IB[0].size(); bx++) {
                            if (s+by < 20 && t+bx < 20) {
                                C[s+by][t+bx] = IB[by][bx];
                            }
                        }
                    }

                    bool flag = true;
                    for (int y = 0; y < IX.size(); y++) {
                        for (int x = 0; x < IX[0].size(); x++) {
                            if (C[10+y][10+x] != IX[y][x]) flag = false;
                        }
                    }

                    if (!flag) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}