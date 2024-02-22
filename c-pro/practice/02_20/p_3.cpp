#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    int range = pow(N, 1/5);
    int res = 0;
    for (int c = 1; c <= range; c++) {
        for (int b = 1; b < c; b++) {
            for (int a = 1; a < b; a++) {
                if (judge(c) && judge(b) && judge(a)) res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}