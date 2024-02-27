#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    long double K; cin >> K;
    vector<ll> S(N);
    vector<ll> T(N);
    for (int i = 0; i < N; i++) {
        long double a, b; cin >> a >> b;
        S[i] = a;
        T[i] = b;
    }

    ll right = 2e10;
    ll left = 0;
    while (right - left > 1) {
        ll sum = 0;
        ll mid = left - (left - right)/2;
        for (int i = 0; i < N; i++) {
            if (S[i] >= mid) {
                sum += T[i];
            }
        }
        if (sum <= K) {
            right = mid;
        }
        else left = mid;
    }
    cout << right << endl;
    return 0;
}