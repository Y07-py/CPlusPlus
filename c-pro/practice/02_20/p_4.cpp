#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    ll N; cin >> N;

    auto ten = [&](string s) {
        ll x = 0;
        for (char c: s) x = x*2+(c-'0');
        return x;
    };

    auto f = [&](string s) {
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '?') S[i] = '0';
        }
        return ten(S) <= N;
    };

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            S[i] = '1';
            if (!f(S)) S[i] = '0';
        }
    }

    cout << ten(S) << endl;
    return 0;
}