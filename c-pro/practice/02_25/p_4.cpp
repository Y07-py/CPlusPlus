#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    vector<int> AC(N, 0);
    set<int> AS;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        AS.insert(a);
        A[i] = a;
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        B[i] = b;
    }
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        int b = B[c-1];
        if (AS.find(b) != AS.end()) {
            AC[b-1]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += AC[A[i]-1];
    }
    cout << ans << endl;
    return 0;
}