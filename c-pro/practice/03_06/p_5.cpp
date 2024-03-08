#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

struct frac {
    ll a, b;
    frac(ll _a = 0, ll _b = 0): a(_a), b(_b) {
        if (b == 0) { a = 1; return;}
        if (b < 0) a = -a, b = -b;
        ll g = gcd(abs(a), b);
        a /= g;
        b /= g;
    }

    bool operator<(const frac& x) const {
        return a*x.b < x.a*b;
    }
};

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    set<frac> st;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            st.insert(frac(X[i]-X[j], Y[i]-Y[j]));
        }
    }
    cout << st.size()*2 << endl;
    return 0;
}