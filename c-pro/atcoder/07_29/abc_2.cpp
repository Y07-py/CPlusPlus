#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> Area(N);
    for (int i = 0; i < N; i++) {
        cin >> Area[i];
    }
    int start_H = 0, start_W = 0;
    vector<pair<int, int> > anser;
    while (start_H < N) {
        bool flag_1 = false;
        bool flag_2 = false;

        if (N >= 9 && M >= 9) {
            flag_1 = true;
        }

        int check_1 = 0;
        int check_2 = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (Area[start_H + i][start_W + j] == '#') {
                    if (i < 3 && j < 3) {
                        check_1++;
                    }
                }
                if (j == 3 && Area[start_H + i][start_W + 3] == '.') {
                    check_2++;
                }
                if (i == 3 && j == 3 && Area[start_H + 3][start_W + 3] == '.') {
                    check_2++;
                }
            }
        }
        
        cout << check_1 << " " << check_2 << endl;
        start_H += 8;
        start_W += 8;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (Area[start_H + i][start_W + j] == '#') {
                    check_1++;
                }
                if (Area[start_H-1][start_W + j] == '.') {
                    check_2++;
                }
                if (Area[start_H + i][start_W-1] == '.') {
                    check_2++;
                }
            }
        }
        if (check_1 == 18 && check_2 == 14) {
            flag_2 = true;
        }
        if (flag_1 && flag_2) {
            anser.push_back(make_pair(start_H-8, start_W-8));
        }
        start_H -= 8;
        if (start_W + 16 > M) {
            start_H++;
            start_W = 0;
        } else {
            start_W += 8;
        }
    }
    for (int i = 0; i < anser.size(); i++) {
        cout << anser[i].first << " " << anser[i].second << endl;
    }
    return 0;

}