#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(ll N) {
    int res = 0;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N%i == 0) {
            res++;
        }
    }
    return res;
}

bool judgesqrt(int N) {
    for (int i = 1; i <= sqrt(N); i++) {
        if (i*i == N) {
            return true;
        }
    }
    return false;
}

int main() {
    int N; cin >> N;
    ll memo[N+1];
    for (int i = 1; i < N; i++) {
        memo[i] = count(i);
    }
    ll res = 0;
    for (int ab = 1; ab < N; ab++) {
        int cd = N - ab;
        int patern1, patern2;
        if (judgesqrt(ab)) {
            patern1 = memo[ab]*2-1;
        } else {
            patern1 = memo[ab]*2;
        }
        if (judgesqrt(cd)) {
            patern2 = memo[cd]*2-1;
        } else {
            patern2 = memo[cd]*2;
        }
        res += patern1 * patern2;
    }
    cout << res << endl;
    return 0;
}