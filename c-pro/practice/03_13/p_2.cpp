#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    ll X; cin >> X;
    string S; cin >> S;
    string T;
    for (char c: S) {
        if (c == 'U') {
            if (!T.empty() && T.back() != 'U') T.pop_back();
            else T.push_back(c);
        } else {
            T.push_back(c);
        }
    }
    for (char c: T) {
        if (c == 'R') X = 2*X+1;
        if(c == 'L') X *= 2;
        if (c == 'U') X /= 2;
    }
    cout << X << endl;
    return 0;
}