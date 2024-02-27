#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C; cin >> A >> B >> C;
    if (C % 2 == 0) C = 2;
    else C = 1;

    if (pow(A, C) == pow(B, C)) cout << '=' << endl;
    else if (pow(A, C) < pow(B, C)) cout << '<' << endl;
    else cout << '>' << endl;
    return 0;
}