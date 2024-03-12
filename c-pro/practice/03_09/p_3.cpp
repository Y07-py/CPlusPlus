#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = K;
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }
    for (int i = 0; i < K; i++) {
        if (mp.find(i) == mp.end()) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}