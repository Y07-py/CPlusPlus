#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    if (A == B) {
        cout << "Draw" << endl;
    } else if (A == 1) {
        cout << "Alice" << endl;
    } else if (B == 1) {
        cout << "Bob" << endl;
    } else if (A > B) {
        cout << "Alice" << endl;
    } else if (A < B) {
        cout << "Bob" << endl;
    }
    return 0;
}