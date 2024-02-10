#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> S, int N) {
    int res = 0;
    int right = 0;

    for (int left = 0; left < N; left++) {
        while (S[right + 1] > S[right]) right++;
        res += right - left + 1;
        if (right == left) right++;
    }
    return res;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int res = solve(A, N);
    cout << res << endl;
    return 0;
}