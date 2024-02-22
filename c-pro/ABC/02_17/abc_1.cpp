#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < 2*N+1; i++) {
        if (i%2 == 0) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}