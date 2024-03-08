#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, T; cin >> N >> T;
    vector<ll> A(N, 0);
    map<ll, ll> mp;
    mp[0] += N;
    ll res = 1;
    for (int i = 0 ; i < T; i++) {
        int a; cin >> a;
        a--;
        ll b; cin >> b;
        mp[A[a]]--;
        if (mp[A[a]] == 0) {
            res--;
        }
        A[a] += b;
        if (mp.find(A[a]) == mp.end()) {
            res++;
        } else {
            if (mp[A[a]] == 0) {
                res++;
            }
        }
        mp[A[a]]++;
        cout << res << endl;
    }
    return 0;
}