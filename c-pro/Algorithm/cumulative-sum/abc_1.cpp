#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i =0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> CS(N+1);
    CS[0] = 0;
    for (int i = 1; i < N+1; i++) {
        CS[i] = CS[i-1] + A[i-1];
    }
    for (int i = 1; i <= N; i++) {
        ll ans = 0;
        for (int left = 0; left + i <= N; left++) {
            int right = left + i;
            ll tmp = CS[right] - CS[left];
            chmax(ans, tmp);
        }
        cout << ans << endl;
    }

    return 0;
}