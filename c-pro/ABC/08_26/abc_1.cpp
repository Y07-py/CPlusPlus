#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX = 101;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, H, X; cin >> N >> H >> X;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int res = MAX;
    for (int i = 0; i < N; i++) {
        if (H + P[i] >= X) {
            chmin(res, i+1);
        } 
    }
    cout << res << endl;
    return 0;
}