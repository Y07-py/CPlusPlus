#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int max_a = A[A.size()-1];
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < max_a) {
            ans = max(ans, A[i]);
        }
    }
    cout << ans << endl;
    return 0;
}