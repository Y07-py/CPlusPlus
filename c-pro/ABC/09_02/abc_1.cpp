#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, P; cin >> N >> M >> P;
    int res = 0;
    while (M <= N) {
        M += P;
        res++;
    }
    cout << res << endl;
    return 0;
}