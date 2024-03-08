#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<double> time(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < N; i++) {
        time[i] = double(A[i]) / double(B[i]);
    }
    vector<double> S(N+1, 0);
    for (int i = 1; i < N; i++) {
        S[i] = S[i-1] + time[i] - time[i-1];
    }
    
    return 0;
}