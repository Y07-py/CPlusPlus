#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> A[i];
    }
    int res = -1;
    for (int i = 0; i <= 100; i++) {
        vector<int> tmp = A;
        tmp.push_back(i);
        sort(tmp.begin(), tmp.end());
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == N-1) continue;
            total += tmp[i];
        }
        res = i;
        if (res >= 0 && res <= 100 && X <= total) {
            break;
        }
        res = -1;
    }
    cout << res << endl;
    return 0;
}