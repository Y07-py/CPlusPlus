#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C; 
    cin >> A >> B >> C;
    for (int i = 1; i < B+1; ++i) {
        int ans = A * i;
        if (ans % B == C) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}