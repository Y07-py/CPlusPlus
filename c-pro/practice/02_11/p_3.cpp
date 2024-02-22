#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e6;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    bool judge = false;
    map<pair<int, int>, int> field;
    pair<int, int> p = make_pair(0, 0);
    field[p] = 1;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        if (c == 'R') {
            p.first += 1; 
        }
        if (c == 'L') {
            p.first -= 1;
        }
        if (c =='U') {
            p.second += 1;
        }
        if (c == 'D') {
            p.second -= 1;
        }
        if (field[p] != 0) judge = true;
        else field[p] = 1;
    }
    if (judge) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}