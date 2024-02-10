#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<tuple<int, int, int> > dp(N);
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];

    for (int i = 0; i < N; i++) {
        dp[i] = 
    }
    return 0;
}