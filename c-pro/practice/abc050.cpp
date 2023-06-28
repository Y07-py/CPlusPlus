#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A; cin >> A;
    char op; cin >> op;
    ll B; cin >> B;
    if (op == '+') {
        cout << A + B << endl;
    }
    else {
        cout << A - B << endl;
    }
    return 0;
}