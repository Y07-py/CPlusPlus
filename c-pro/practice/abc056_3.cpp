#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X; cin >> X;
    bool flag = false;
    ll time = 0;
    ll total = 0;
    while(1) {
        time++;
        total += time;
        if (total >= X) {
            cout << time << endl;
            break;
        }
    }
    return 0;
}