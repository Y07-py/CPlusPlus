#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X, A, B; cin >> X >> A >> B;
    if (A-B < 0) {
        ll dif = B - A;
        if (dif < X + 1) {
            cout << "safe" << endl;
        } else {
            cout << "dangerous" << endl;
        }
    } else {
        cout << "delicious" << endl;
    }
    return 0;
}