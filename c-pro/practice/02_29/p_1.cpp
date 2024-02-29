#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    string res = "";

    while (N > 0) {
        if (N%2 == 1) {
            res.push_back('A');
            N--;
        } else {
            res.push_back('B');
            N /= 2;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}