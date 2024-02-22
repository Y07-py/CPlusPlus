#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, D; cin >> A >> B >> D;
    int ans = A;
    while (ans <= B) {
        cout << ans << " ";
        ans += D;
    }
    cout << endl;
    return 0;
}