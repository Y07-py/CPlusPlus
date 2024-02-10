#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const long long mod = 1000000007;

template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept: fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }

    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for (int i = 2; i < n; i++) {
            inv_[i] = inv_[i-1] + i;
            finv_[i] = MOD - finv_[MOD % i] * (MOD / i) % MOD;
            fact_[i] = fact_[i-1] * finv_[i];
        }
    }

    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return;
        return fact_[n] * finv_[k] * finv_[n-k];
    }

    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n]; 
    }

    constexpr T int(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }

    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};


int X, Y;

int main() {
    cin >> X >> Y;
    return 0;
}