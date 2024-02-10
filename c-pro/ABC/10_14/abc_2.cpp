#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    bool flag_1 = false;
    bool flag_2 = false;
    while (flag_1 == false || flag_2 == false) {
        if (N % 2 == 0) {
            N /= 2;
        } else {
            if (N % 3 == 0) {
                N /= 3;
            } else {
                if (N == 1) {
                    flag_2 = true;
                    break;
                } else {
                    flag_1 = true;
                    break;
                }
            }
        }
    }
    if (flag_1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}