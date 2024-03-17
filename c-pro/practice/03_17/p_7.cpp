#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    int top = 0;
    for (int i = 0; i < Q; i++) {
        int n; cin >> n;
        int x; cin >> x;
        if (n == 1) {
            top = (top-x+N) % N;
        } else {
            cout << S[(top+x-1)%N] << endl;
        }
    }
    return 0;
}